{-
-- EPITECH PROJECT, 2023
-- DoOp.hs
-- File description:
-- Pool day02
-}

import Data.Char
import Control.Monad

myElem :: Eq a => a -> [a] -> Bool
myElem i [] = False
myElem i (a:as)
  | i == a = True
  | otherwise = myElem i as

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv a i = Just(a `div` i)

safeNth :: [a] -> Int -> Maybe a
safeNth (a:as) i
  | i < 0 = Nothing
  | i >= length(as) + 1 = Nothing
safeNth (a:as) 0 = Just a
safeNth (a:as) i = (safeNth as (i - 1))

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just a) = Just (a + 1)

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup _ [] = Nothing
myLookup a ((b,i):bs)
  | a == b = Just i
  | otherwise = myLookup a bs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo f _ Nothing = Nothing
maybeDo a (Just b) (Just c) = Just (a b c)

numberChecker :: String -> Bool
numberChecker = all isDigit

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt i
    | numberChecker i == False = Nothing
    | otherwise = Just (read i :: Int)

getLineLength :: IO Int
getLineLength = (length) <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength i = (putStrLn i) >> return (length i)

printBox :: Int -> IO ()
printBox i | i < 0 = return ()
printBox 0 = return ()
printBox 1 = putStrLn "++"
printBox size =
  putStrLn ("+" ++ ['-' | size <- [1..((size-1)*2)]] ++ "+") >>
  putStr (concat (replicate (size -2)
                  (("|" ++ [' ' | size <- [1..((size-1)*2)]]
                    ++ "|" ++ "\n")))) >>
  putStrLn ("+" ++ ['-' | size <-[1..(size-1)*2]] ++ "+")

concatLines :: Int -> IO String
concatLines i
  | i <= 0 = return ("")
  | otherwise = do
      u <- replicateM i getLine
      return $ concat u

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine
