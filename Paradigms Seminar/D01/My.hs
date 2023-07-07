{-
-- EPITECH PROJECT, 2023
-- My.hs
-- File description:
-- My.hs
-}

mySucc :: Int -> Int
mySucc i = i + 1

myIsNeg :: Int -> Bool
myIsNeg i
  | i < 0 = True
  | i >= 0 = False

myAbs :: Int -> Int
myAbs i
  | i < 0 = i * (-1)
  | i >= 0 = i

myMin :: Int -> Int -> Int
myMin i e
  | i < e = i
  | e < i = e

myMax :: Int -> Int -> Int
myMax i e
  | i > e = i
  | e > i = e

myTuple :: a -> b -> (a,b)
myTuple a b = (a,b)

myTruple :: a -> b -> c -> (a,b,c)
myTruple a b c = (a,b,c)

myFst :: (a,b) -> a
myFst (a,b) = a

mySnd :: (a,b) -> b
mySnd (a,b) = b

mySwap :: (a,b) -> (b,a)
mySwap (a,b) = (b,a)

myHead :: [a] -> a
myHead (a:as) = a
myHead [] = error "Error list empty"

myTail :: [a] -> [a]
myTail (a:as) = as
myTail [] = error "Error list empty"

myLength :: [a] -> Int
myLength [] = 0
myLength (a:as) = (+1) (myLength as)

myNth :: [a] -> Int -> a
myNth (a:as) i
  | i < 0 = error "Index negative"
  | i > myLength(as) + 1 = error "Index too hight"
myNth (a:as) 0 = a
myNth (a:as) i = (myNth as (i - 1))

myTake :: Int -> [a] -> [a]
myTake i [] = error "Not good"
myTake 0 (a:as) = []
myTake i (a:as) = a:(myTake (i-1) as)

myDrop :: Int -> [ a ] -> [ a ]
myDrop i (a:as)
    | i >= myLength(as) + 1 = error "Too long"
myDrop 1 (a:as) = as
myDrop i (a:as) = (myDrop (i-1) as)

myAppend :: [a] -> [a] -> [a]
myAppend [] [] = []
myAppend [] i = i
myAppend i [] = i
myAppend (a:as) b = a : myAppend as b

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:as) = myAppend (myReverse as) [a]

myInit :: [a] ->[a]
myInit (a:[]) = []
myInit (a:as) = a:myInit as

myLast :: [a] -> a
myLast [] = error "Error list is empty"
myLast (a:[]) = a
myLast (a:as) = myLast(as)

myZip :: [a] -> [b] -> [(a,b)]
myZip a [] = []
myZip [] b = []
myZip (a:as) (b:bs) = (a,b):(myZip as bs)

myUnzip :: [(a,b)] -> ([a],[b])
myUnzip [] = ([],[])
myUnzip ((a,b):as) = (a:as1, b:bs1)
    where (as1, bs1) = myUnzip as

myMap :: (a->b) -> [a] -> [b]
myMap f [] = []
myMap f (a:as) = f a : myMap f as

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter f [] = []
myFilter f (a:as)
    | f a = a : myFilter f as
    | otherwise = myFilter f as
