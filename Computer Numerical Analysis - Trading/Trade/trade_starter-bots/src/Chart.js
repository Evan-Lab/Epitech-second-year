/*
** EPITECH PROJECT, 2023
** Trade
** File description:
** Chart.js
*/

module.exports = class Chart {
    constructor() {
        this.candles = {};
    }

    addCandle(candle) {
        this.candles[candle.date.getTime()] = candle;
    }

    getCandleAt(date) {
        return this.candles[date.getTime()];
    }
};
