/*
** EPITECH PROJECT, 2023
** Trade
** File description:
** HOLDStrategy.js
*/

const Order = require('./Order');

module.exports = class MACDStrategy {
    constructor() {
        this.close_values = [];
    }

    execute(state) {
        const dollars = state.stacks['USDT'];
        const btc = state.stacks['BTC'];
        const lastClosePrice = state.charts['USDT_BTC'].getCandleAt(state.date).close;
        const amount = dollars / lastClosePrice;
        const portfolioPercentage = 0.5;

        const states = Object.entries(state.charts['USDT_BTC'].candles);
        for (let i = 0; i < states.length; i++) {
            this.close_values.push(states[i][1].close);
        }

        const { macdLine, signalLine, histogram } = this.calculateMACD(this.close_values);

        if (macdLine > signalLine && histogram > 0) {
            process.stderr.write('Buy\n');
            const order = new Order('buy', 'USDT_BTC', amount);
            return order.toString();
        } else if (macdLine < signalLine && histogram < 0) {
            process.stderr.write('Sell\n');
            const order = new Order('sell', 'USDT_BTC', btc);
            return order.toString();
        } else {
            process.stderr.write('Pass\n');
            return 'pass';
        }
    }

    calculateMACD(close_prices) {
        const shortEMA = this.calculateEMA(close_prices, 12);
        const longEMA = this.calculateEMA(close_prices, 26);
        const macdLine = shortEMA - longEMA;
        const signalLine = this.calculateEMA([macdLine], 9);
        const histogram = macdLine - signalLine;

        return { macdLine, signalLine, histogram };
    }

    calculateEMA(data, period) {
        let ema = 0;
        const multiplier = 2 / (period + 1);

        for (let i = 0; i < period; i++) {
            ema += data[data.length - 1 - i];
        }

        ema /= period;

        for (let i = data.length - period - 1; i >= 0; i--) {
            ema = (data[i] - ema) * multiplier + ema;
        }

        return ema;
    }
};
