/*
** EPITECH PROJECT, 2023
** Trade
** File description:
** strategy.js
*/

const BollingerStrategy = require('./BollingerStrategy');
const IchimokuStrategy = require('./IchimokuStrategy');
const Order = require('./Order');

var stop_loss = false;

module.exports = class CombinedStrategy {
    constructor() {
        this.bollingerStrategy = new BollingerStrategy();
        this.ichimokuStrategy = new IchimokuStrategy();
    }

    execute(state) {
        const dollars = state.stacks['USDT'];
        const btc = state.stacks['BTC'];
        const portfolioPercentage = 1;
        const sellAmount = btc * portfolioPercentage;
        const lastClosePrice = state.charts['USDT_BTC'].getCandleAt(state.date).close;
        const amount = dollars / lastClosePrice;

        const delay = 4;
        state.initialPrice = state.initialPrice || 0;
        state.counter = state.counter || 0;
        state.counter++;

        if (state.counter == 1)
            state.initialPrice = state.charts['USDT_BTC'].getCandleAt(state.date).close;

        if (state.counter >= delay) {
            const currentPrice = state.charts['USDT_BTC'].getCandleAt(state.date).close;
            if ((currentPrice < 0.9 * state.initialPrice && btc > 0.0001)) {
                stop_loss = true;
                process.stderr.write('Stop loss triggered\n');
                const order = new Order('sell', 'USDT_BTC', sellAmount);
                return order.toString();
            }
            state.counter = 0;
            if (stop_loss == true && currentPrice >= state.initialPrice * 1.1) {
                stop_loss = false;
            }
        }

        const bollingerAction = this.bollingerStrategy.execute(state);
        const IchimokuAction = this.ichimokuStrategy.execute(state);

        if (bollingerAction.startsWith('Buy') && IchimokuAction.startsWith('Buy') && stop_loss == false) {
            process.stderr.write('Bollinger & Ichimoku Buy\n');
            const order = new Order('buy', 'USDT_BTC', amount);
            return order.toString();
        } else if (bollingerAction.startsWith('Sell') && IchimokuAction.startsWith('Sell')) {
            process.stderr.write('Bollinger & Ichimoku Sell\n');
            const order = new Order('sell', 'USDT_BTC', sellAmount);
            return order.toString();
        } else {
            return 'pass';
        }
    }
};
