module CodeWars where

factorial :: Integer -> Integer 
factorial 0 = 1
factorial x = x * factorial (x - 1)

choose :: Integer -> Integer -> Integer 
choose n x = factorial n `div` factorial x `div` factorial (n - x)
checkchoose :: Integer -> Integer -> Integer 
checkchoose m n = if null t then -1 else head t
    where
        t = filter (\x -> choose n x == m) [1..n `div` 2]
