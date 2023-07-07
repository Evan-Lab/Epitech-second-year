/*
** EPITECH PROJECT, 2023
** Trade
** File description:
** RSIStrategy
*/

const Order = require('./Order');

module.exports = class RSIStrategy {
    constructor() {
        this.close_values = [];
    }

    execute(state) {
        const dollars = state.stacks['USDT'];
        const lastClosePrice = state.charts['USDT_BTC'].getCandleAt(state.date).close;
        const states = Object.entries(state.charts['USDT_BTC'].candles);
        const amount = dollars / lastClosePrice;

        for (let i = 0; i < states.length; i++)
            this.close_values.push(states[i][1].close);

        const rsi = this.calculateRSI(this.close_values);
        const max_rsi = 70;
        const min_rsi = 30;

        if (rsi >= min_rsi && rsi <= max_rsi) {
            return 'pass';
        } else if (rsi < min_rsi && amount > 0) {
            process.stderr.write('RSI Buy\n');
            process.stderr.write('Buy\n');
            return 'Buy';
        } else if (rsi > max_rsi && amount > 0) {
            process.stderr.write('RSI Sell\n');
            return 'Sell';
        } else {
            return 'pass';
        }
    }

    calculateRSI(close_prices, period = 14) {

        const changes = [];

        if (close_prices.length <= period)
            return null;

        for (let i = 1; i < close_prices.length; i++)
            changes.push(close_prices[i] - close_prices[i - 1]);

        let gainsSum = 0;
        let lossesSum = 0;

        for (let i = 0; i < period; i++) {
            if (changes[i] > 0)
                gainsSum += changes[i];
            else
                lossesSum += Math.abs(changes[i]);
        }

        let prevAvgGain = gainsSum / period;
        let prevAvgLoss = lossesSum / period;

        for (let i = period; i < changes.length; i++) {
            const currentChange = changes[i];
            let avgGain, avgLoss;
            if (currentChange > 0) {
                avgGain = (prevAvgGain * (period - 1) + currentChange) / period;
                avgLoss = (prevAvgLoss * (period - 1)) / period;
            } else {
                avgGain = (prevAvgGain * (period - 1)) / period;
                avgLoss = (prevAvgLoss * (period - 1) + Math.abs(currentChange)) / period;
            }
            prevAvgGain = avgGain;
            prevAvgLoss = avgLoss;
        }

        const relativeStrength = prevAvgGain / prevAvgLoss;
        const rsi = 100 - (100 / (1 + relativeStrength));
        return rsi;
    }
};
