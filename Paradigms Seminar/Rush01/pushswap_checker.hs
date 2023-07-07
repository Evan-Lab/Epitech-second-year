{-
-- EPITECH PROJECT, 2023
-- pushswap_checker
-- File description:
-- rush1
-}

import Data.Char
import System.Environment
import Text.Read
import System.Exit

numberChecker :: String -> Bool
numberChecker = all isDigit

myTake :: Int -> [ a ] -> [ a ]
myTake b [] = error "ca marche pas"
myTake 0 (a:as) = []
myTake b (a:as) = a:(myTake (b-1) as)

myNth :: [ a ] -> Int -> a
myNth (a:as) b
    | b < 0 = error "ca marche pas"
    | b > myLength(as) + 1 = error "ca marche toujours pas"
myNth (a:as) 0 = a
myNth (a:as) b = (myNth as (b-1))

myAppend :: [ a ] -> [ a ] -> [ a ]
myAppend [] [] = []
myAppend a [] = a
myAppend [] b = b
myAppend (a:as) b = a : myAppend as b

myDrop :: Int -> [ a ] -> [ a ]
myDrop b [] = error "ca marche pas"
myDrop 1 (a:as) = as
myDrop b (a:as) = (myDrop (b-1) as)

myLength :: [ a ] -> Int
myLength [] = 0
myLength (a:as) = (+1) (myLength as)

myTail :: [ a ] -> [ a ]
myTail [] = error "error list is empty"
myTail (a:as) = as

pa :: ([a],[a]) -> ([a],[a])
pa (a,[]) = (a,[])
pa (a,(b:bs)) = ((myAppend (b:[]) a) , bs)

pb :: ([a],[a]) -> ([a],[a])
pb ([],b) = ([],b)
pb ((a:as),b) = (as ,(myAppend (a:[]) b))

ra :: ([a],[a]) -> ([a],[a])
ra ([],b) = ([],b)
ra ((a:as),b) = ((myAppend as (a:[])),b)

rb :: ([a],[a]) -> ([a],[a])
rb (a,[]) = (a,[])
rb (a,(b:bs)) = (a,(myAppend bs (b:[])))

rr :: ([a],[a]) -> ([a],[a])
rr (a,[]) = (a,[])
rr ([],b) = ([],b)
rr ((a:as),(b:bs)) = ((myAppend as (a:[])) , (myAppend bs (b:[])))

rra :: ([a],[a]) -> ([a],[a])
rra ([],b) = ([],b)
rra ((a:as),b) = ((myAppend ((myNth as ((myLength as) - 1)):[])
    (myAppend (a:[]) (myTake ((myLength as) - 1) as))), b)

rrb :: ([a],[a]) -> ([a],[a])
rrb (a,[]) = (a,[])
rrb (a,(b:bs)) = (a , (myAppend ((myNth bs ((myLength bs) - 1)):[])
    (myAppend (b:[]) (myTake ((myLength bs) - 1) bs))))

rrr :: ([a],[a]) -> ([a],[a])
rrr (a,[]) = (a,[])
rrr ([],b) = ([],b)
rrr ((a:as),(b:bs)) = ( (myAppend ((myNth as ((myLength as) - 1)):[])
    (myAppend (a:[]) (myTake ((myLength as) - 1) as))),
    (myAppend ((myNth bs ((myLength bs) - 1)):[])
    (myAppend (b:[]) (myTake ((myLength bs) - 1) bs))) )

sa :: ([String], [String]) -> ([String], [String])
sa ([], b) = ([], b)
sa (x:y:xs, b) = (y:x:xs, b)

sb :: ([a], [b]) -> ([a], [b])
sb (a, []) = (a, [])
sb (a, x:y:xs) = (a, y:x:xs)

sc :: ([b], [b]) -> ([b], [b])
sc (a:b:c, []) = (b:a:c, [])
sc ([], d:e:f) = ([], e:d:f)
sc (a:b:c, d:e:f) = (b:a:c , e:d:f)

repart2 :: String -> ([String], [String]) -> ([String], [String])
repart2 "sa" a = sa a
repart2 "sb" a = sb a
repart2 "sc" a = sc a
repart2 "pa" a = pa a
repart2 "pb" a = pb a
repart2 "ra" a = ra a
repart2 "rb" a = rb a
repart2 "rr" a = rr a
repart2 "rra" a = rra a
repart2 "rrb" a = rrb a
repart2 "rrr" a = rrr a

repart1 :: [String] -> ([String], [String]) -> ([String], [String])
repart1 [] b = b
repart1 (a:as) b = repart1 as (repart2 a b)

checkTri :: [String] -> [String]
checkTri [a:[]] = []
checkTri (a:as)
    | (read a::Int) <= (read (head as)::Int) = checkTri as
    | otherwise = as

check :: ([String], [String]) -> IO ()
check (a, b)
    | myLength b /= 0 = print "KO"
    | myLength (checkTri a) /= 0 = print "KO"
    | otherwise = print "OK"

checkArgsInt :: [String] -> IO ()
checkArgsInt [] = return ()
checkArgsInt (a:as)
    | numberChecker a == False = exitWith (ExitFailure 84)
    | otherwise = checkArgsInt as

checkArgsCommand :: [String] -> IO ()
checkArgsCommand [] = return ()
checkArgsCommand ("sa":as) = checkArgsCommand as
checkArgsCommand ("sb": as) = checkArgsCommand as
checkArgsCommand ("sc" :as) = checkArgsCommand as
checkArgsCommand ("pa": as) = checkArgsCommand as
checkArgsCommand ("pb" :as) = checkArgsCommand as
checkArgsCommand ("ra" :as) = checkArgsCommand as
checkArgsCommand ("rb" :as) = checkArgsCommand as
checkArgsCommand ("rr" :as) = checkArgsCommand as
checkArgsCommand ("rra" :as) = checkArgsCommand as
checkArgsCommand ("rrb" :as) = checkArgsCommand as
checkArgsCommand ("rrr" :as) = checkArgsCommand as
checkArgsCommand _ = exitWith (ExitFailure 84)

main :: IO ()
main = do
    numbers_list <- getArgs
    actions_list <- getLine
    let all_actions = words actions_list
    checkArgsInt numbers_list
    checkArgsCommand all_actions
    let tuple = repart1 all_actions (numbers_list, [])
    check tuple
