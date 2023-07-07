#!/usr/bin/env python3
##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-clement.martin
## File description:
## main.py
##

import os
import sys
import random
import select
from enum import Enum
import socket
import time

class State(Enum):
    HUNGRY = 1
    SAFE = 2
    EVOLVE = 3

## ===========================================================
## =========================[IA]==============================
## ===========================================================

class TrantorIa:
    def __init__(self):
        self.socket = socket
        self.status = False
        self.state = State.SAFE
        self.level = 1
        self.food = 10
        self.nb_ia = 0
        self.nb_team = 0
        self.slot = 0
        self.team_name = ""
        self.message = ""

## =================================================================
## =========================[CONNEXION]=============================
## =================================================================

    def connect_server(self, ip, port):
        try:
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.socket.connect((ip, port))
            self.status = True
            print("Connection to server on port", port)
        except Exception as e:
            print("Error connecting to the server:", str(e))

    def close_connection(self):
        try:
            self.socket.close()
        except Exception as e:
            print("Error closing the connection:", str(e))


## ============================================================
## =========================[MOVE]=============================
## ============================================================

    def forward(self, buffer_size):
        try:
            self.socket.send("Forward\n".encode())
            time.sleep(0.1)
        except Exception as e:
            print("Error performing forward action:", str(e))

    def right(self, buffer_size):
        try:
            self.socket.send("Right\n".encode())
            time.sleep(0.1)
        except Exception as e:
            print("Error performing right action:", str(e))

    def left(self, buffer_size):
        try:
            self.socket.send("Left\n".encode())
            time.sleep(0.1)
        except Exception as e:
            print("Error performing left action:", str(e))

    def look(self, buffer_size, response):
        try:
            self.socket.send("Look\n".encode())
            time.sleep(0.1)
            parsed_response = response.strip('[]').split(',')
            tiles = [tile.strip().replace("'", "") for tile in parsed_response[1:]]
            return tiles
        except Exception as e:
            print("Error performing look action:", str(e))

    def rotate_towards_tile(self, buffer_size, tile_index, response):
        orientation_mapping = {
            0: 'UP',
            1: 'RIGHT',
            2: 'DOWN',
            3: 'LEFT'
        }

        tiles = self.look(buffer_size, response)
        if not tiles:
            return

        current_tile = tiles[0]
        current_index = tiles.index(current_tile)

        target_tile = tiles[tile_index]
        target_index = tiles.index(target_tile)

        current_orientation = orientation_mapping[current_index]
        target_orientation = orientation_mapping[target_index]

        rotation_direction = ''
        rotation_amount = 0

        if current_orientation == target_orientation:
            return
        elif (current_index - target_index) % 2 == 0:
            rotation_direction = 'RIGHT'
            rotation_amount = (current_index - target_index) // 2
        else:
            rotation_direction = 'LEFT'
            rotation_amount = (current_index - target_index + 1) // 2

        for _ in range(rotation_amount):
            if rotation_direction == 'RIGHT':
                self.right(buffer_size)
            else:
                self.left(buffer_size)

## ==============================================================
## =========================[OBJECT]=============================
## ==============================================================

    def inventory(self, buffer_size, response):
        try:
            self.socket.send("Inventory\n".encode())
            time.sleep(0.1)
            parsed_response = response.strip('[]').split(',')
            items = [item.strip().replace("'", "") for item in parsed_response[1:]]
            return items
        except Exception as e:
            print("Error performing inventory action:", str(e))

    def take_object(self, buffer_size, object):
        try:
            self.socket.send(("Take " + object + "\n").encode())
            time.sleep(0.1)
        except Exception as e:
            print("Error performing take action:", str(e))

    def set_object(self, buffer_size, object):
        try:
            self.socket.send(("Set " + object + "\n").encode())
            time.sleep(0.1)
        except Exception as e:
            print("Error performing set action:", str(e))

## ==============================================================
## =========================[ACTION]=============================
## ==============================================================

    def connect_nbr(self, buffer_size):
        try:
            self.socket.send("Connect_nbr\n".encode())
        except Exception as e:
            print("Error performing connect_nbr action:", str(e))

    def start_incantation(self, buffer_size, response):
        try:
            self.socket.send("Incantation\n".encode())
            time.sleep(0.1)
        except Exception as e:
            print("Error performing left action:", str(e))

## =============================================================
## =========================[STATE]=============================
## =============================================================

    def state_eat(self, buffer_size, response):
        state = State.HUNGRY
        tiles = self.look(buffer_size, response)
        inventory = self.inventory(buffer_size, response)
        choices = ['forward', 'left', 'right']

        if "food" in inventory:
            food_count = inventory.count("food")
        else:
            food_count = 0

        if food_count < 7:
            if tiles is None:
                return state, inventory

            food_tiles = [i for i, tile in enumerate(tiles) if tile == "food"]

            if not food_tiles:
                action = random.choice(choices)

                if action == 'forward':
                    self.forward(buffer_size)
                elif action == 'left':
                    self.left(buffer_size)
                elif action == 'right':
                    self.right(buffer_size)
            else:
                closest_food_index = min(food_tiles)
                self.rotate_towards_tile(buffer_size, closest_food_index, response)
                if closest_food_index != 0:
                    self.forward(buffer_size)
                self.take_object(buffer_size, "food")
                food_count += 1
                inventory.append("food")
        else:
            state = State.SAFE

        return state, inventory

    def state_safe(self, buffer_size, response):
        state = State.SAFE
        tiles = self.look(buffer_size, response)
        inventory = self.inventory(buffer_size, response)
        choices = ['forward', 'left', 'right']

        linemate_tiles = [i for i, tile in enumerate(tiles) if tile == "linemate"]

        if not linemate_tiles:
            action = random.choice(choices)

            if action == 'forward':
                self.forward(buffer_size)
            elif action == 'left':
                self.left(buffer_size)
            elif action == 'right':
                self.right(buffer_size)
        else:
            closest_linemate_index = min(linemate_tiles)
            self.rotate_towards_tile(buffer_size, closest_linemate_index, response)
            if closest_linemate_index != 0:
                self.forward(buffer_size)
            self.take_object(buffer_size, "linemate")
            inventory.append("linemate")

        if "food" in inventory:
            food_count = inventory.count("food")
        else:
            food_count = 0

        if food_count < 7:
            state = State.HUNGRY

    def state_incantation(self, buffer_size, response):
        state = State.EVOLVE
        self.set_object(buffer_size, "linemate")
        self.start_incantation(buffer_size)
        if "Elevation underway" in response:
            state = State.SAFE
        return state

    def play(self, buffer_size, response):
        if self.state == State.HUNGRY:
            self.state_eat(buffer_size, response)
        elif self.state == State.SAFE:
            self.state_safe(buffer_size, response)

## ============================================================
## =========================[CORE]=============================
## ============================================================

    def receive_connection(self, buffer_size, team_name, port, ip):
        self.connect_server(ip, port)
        self.socket.send((team_name + "\n").encode())
        while self.status:
            try:
                ready_to_read, _, _ = select.select([self.socket], [], [], 5000)
                if self.socket in ready_to_read:
                    data = self.socket.recv(buffer_size)
                    response = data.decode()
                    print(response)
                    if "dead" in data.decode():
                        self.status = False
                        self.close_connection()
                    else:
                        self.play(buffer_size, response)
            except (BrokenPipeError, ConnectionError) as e:
                print("Socket connection closed unexpectedly:", str(e))
                self.status = False
                break

## ==============================================================
## =========================[PARSING]============================
## ==============================================================

def usage():
    print("Usage: ././zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")

def parse_info(info, av, i):
    flags = {"-p": "port", "-n": "name", "-h": "host", "-help": "help"}
    if info in flags:
        if info == "-help":
            usage()
            sys.exit(0)
        if i + 1 >= len(av):
            print("Error: missing argument for flag " + info)
            sys.exit(84)
        return flags[info], av[i + 1]

## ===========================================================
## =========================[MAIN]============================
## ===========================================================

def main():
    trantor_ia = TrantorIa()
    buffer_size = 4096

    if len(sys.argv) < 2:
        usage()
        sys.exit(84)
    for i in range(1, len(sys.argv)):
        if sys.argv[i][0] == '-':
            flag, value = parse_info(sys.argv[i], sys.argv, i)
            if flag == "port":
                trantor_ia.port = int(value)
            elif flag == "name":
                trantor_ia.name = value
            elif flag == "host":
                trantor_ia.host = value
            else:
                usage()
                sys.exit(84)
    trantor_ia.receive_connection(buffer_size, trantor_ia.name, trantor_ia.port, trantor_ia.host)
    trantor_ia.close_connection()

if __name__ == "__main__":
    main()