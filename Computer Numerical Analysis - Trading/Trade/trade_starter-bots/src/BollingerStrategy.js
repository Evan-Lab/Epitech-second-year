/*
** EPITECH PROJECT, 2023
** Trade
** File description:
** HOLDStrategy.js
*/

module.exports = class BollingerStrategy {
    constructor() {
        this.close_values = [];
    }

    execute(state) {
        const dollars = state.stacks['USDT'];
        const btc = state.stacks['BTC'];
        const lastClosePrice = state.charts['USDT_BTC'].getCandleAt(state.date).close;
        const states = Object.entries(state.charts['USDT_BTC'].candles);

        for (let i = 0; i < states.length; i++)
            this.close_values.push(states[i][1].close);

        const { upper_band, lower_band } = this.get_close_values(this.close_values, 20, 2);

        if (lastClosePrice > upper_band + 0.0010 && btc > 0.00001) {
            return 'Sell';
        } else if (lastClosePrice < lower_band - 0.0010 && dollars > 0) {
            return 'Buy';
        } else {
            return 'pass';
        }
    }

    get_close_values(close_prices, period, num_std_dev) {
        const slicedPrices = close_prices.slice(-period);
        const sma = WeightMovingAverage(slicedPrices);
        const ema = calculateExponentialMovingAverage(slicedPrices, period);
        const csma = calculateSimpleMovingAverage(slicedPrices);
        const stdDev = calculateStandardDeviation(slicedPrices, sma);
        const upper_band = sma + (stdDev * num_std_dev);
        const lower_band = sma - (stdDev * num_std_dev);
        return { upper_band, lower_band };
    }
}

function WeightMovingAverage(data) {
    var period = data.length;
    var i = period - 1;
    var weight_sum = period * (period + 1) / 2.0;
    var weighted_sum = 0.0;

    for (var j = i, k = 0; j >= i - period + 1; j--, k++) {
        weighted_sum += data[j] * (k + 1);
    }
    return weighted_sum / weight_sum;
}

function calculateExponentialMovingAverage(data, period) {
    const multiplier = 2 / (period + 1);
    let ema = data[0];

    for (let i = 1; i < data.length; i++)
        ema = (data[i] - ema) * multiplier + ema;
    return ema;
}

function calculateSimpleMovingAverage(data) {
    const sum = data.reduce((acc, value) => acc + value, 0);
    return sum / data.length;
}

function calculateStandardDeviation(data, sma) {
    const sum = data.reduce((acc, value) => acc + Math.pow(value - sma, 2), 0);
    const variance = sum / data.length;
    const stdDev = Math.sqrt(variance);
    return stdDev;
}

function applyStopLoss(close, middleBand, stopLoss) {
    for (let i = 1; i < close.length; i++) {
        if (close[i - 1] < stopLoss[i - 1] && close[i] > stopLoss[i]) {
            console.log("Buy at price:", close[i]);
        } else if (close[i - 1] > stopLoss[i - 1] && close[i] < stopLoss[i]) {
            console.log("Sell at price:", close[i]);
        }
    }
}
