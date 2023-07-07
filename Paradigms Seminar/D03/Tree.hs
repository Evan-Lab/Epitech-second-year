{-
-- EPITECH PROJECT, 2023
-- Tree.hs
-- File description:
-- Pool day 03
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show)
