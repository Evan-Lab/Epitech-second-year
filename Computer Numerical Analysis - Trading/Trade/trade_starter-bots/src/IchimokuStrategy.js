/*
** EPITECH PROJECT, 2023
** Trade
** File description:
** IchimokuStrategy.js
*/

module.exports = class IchimokuStrategy {
    constructor() {
        this.close_values = [];
    }

    execute(state) {
        const dollars = state.stacks['USDT'];
        const btc = state.stacks['BTC'];
        const lastClosePrice = state.charts['USDT_BTC'].getCandleAt(state.date).close;
        const amount = dollars / lastClosePrice;

        const states = Object.entries(state.charts['USDT_BTC'].candles);
        for (let i = 0; i < states.length; i++) {
            this.close_values.push(states[i][1].close);
        }

        const {
            tenkanSen,
            kijunSen,
            senkouSpanA,
            senkouSpanB,
            chikouSpan
        } = this.calculateIchimoku(this.close_values);

        if (
            lastClosePrice < tenkanSen &&
            lastClosePrice < kijunSen &&
            lastClosePrice < senkouSpanA &&
            lastClosePrice < senkouSpanB &&
            lastClosePrice < chikouSpan
            && amount > 0
        ) {
            return 'Buy';
        } else if (
            lastClosePrice > tenkanSen &&
            lastClosePrice > kijunSen &&
            lastClosePrice > senkouSpanA &&
            lastClosePrice > senkouSpanB &&
            lastClosePrice > chikouSpan &&
            btc > 0
        ) {
            return 'Sell';
        } else {
            return 'pass';
        }
    }

    calculateIchimoku(close_prices) {
        const tenkanSen = (Math.max(...close_prices.slice(-9)) + Math.min(...close_prices.slice(-9))) / 2;
        const kijunSen = (Math.max(...close_prices.slice(-26)) + Math.min(...close_prices.slice(-26))) / 2;
        const senkouSpanA = (tenkanSen + kijunSen) / 2;
        const senkouSpanB = (Math.max(...close_prices.slice(-52)) + Math.min(...close_prices.slice(-52))) / 2;
        const chikouSpan = close_prices[close_prices.length - 26];

        return { tenkanSen, kijunSen, senkouSpanA, senkouSpanB, chikouSpan };
    }
};
