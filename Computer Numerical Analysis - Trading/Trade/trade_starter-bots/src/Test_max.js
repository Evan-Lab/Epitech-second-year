/*
** EPITECH PROJECT, 2023
** Trade
** File description:
** HOLDStrategy.js
*/

var global_assending = false;
var global_last_price = 0;
var global_usdt = 1000;
var global_btc = 0;
var global_i = 0;

const Order = require('./Order');

module.exports = class HODLStrategy {
    constructor() {
        this.close_values = [];
    }

    execute(state) {
        var open_price = 0;
        const dollars = state.stacks['USDT'];
        const btc = state.stacks['BTC'];
        open_price = state.charts['USDT_BTC'].getCandleAt(state.date).open;
        const lastClosePrice = state.charts['USDT_BTC'].getCandleAt(state.date).close;
        if (global_last_price == 0) {
            global_last_price = lastClosePrice;
        }
        const amount = dollars / lastClosePrice;
        const portfolioPercentage = 0.5;

        const states = Object.entries(state.charts['USDT_BTC'].candles);
        for (let i = 0; i < states.length; i++) {
            this.close_values.push(states[i][1].close);
        }

        var current_assending = (lastClosePrice - open_price) > 0;

        if (current_assending != global_assending) {

            if (global_assending == true) {
                global_usdt = global_usdt + global_btc * global_last_price * 1;
                global_btc = 0;

            } else {
                global_btc = global_btc + global_usdt / global_last_price * 1;
                global_usdt = 0;
            }

            global_last_price = lastClosePrice;
            global_assending = !global_assending;
        } else {
            if (current_assending == true) {
                process.stderr.write(global_i + ': Still assending, global_last_price: ' + global_last_price + ',' + state.date + '\n');
            } else {
                process.stderr.write(global_i + ': Still dessending, global_last_price: ' + global_last_price + ',' + state.date + '\n');
            }
        }
        process.stderr.write('Global usdt: ' + global_usdt + ' ' + 'Global btc: ' + global_btc + '\n');
        global_i++;
        return 'pass';
    }
}

