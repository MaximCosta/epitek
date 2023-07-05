{-
-- EPITECH PROJECT, 2023
-- pushswap_checker rush 1
-- File description:
-- pushswap_checker.hs
-}

import System.Environment
import Data.List
import System.Exit

data State = State [Int] [Int]

swap :: [a] -> [a]
swap (x:y:xs) = y:x:xs
swap xs = xs

rotate :: [a] -> [a]
rotate (x:xs) = xs ++ [x]
rotate [] = []

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (x:y:xs) = x <= y && isSorted (y:xs)

execute :: State -> String -> State
execute (State l_a l_b) op = case op of
    "sa" -> State (swap l_a) l_b
    "sb" -> State l_a (swap l_b)
    "sc" -> State (swap l_a) (swap l_b)
    "pa" -> State (head l_b : l_a) (tail l_b)
    "pb" -> State (tail l_a) (head l_a : l_b)
    "ra" -> State (rotate l_a) l_b
    "rb" -> State l_a (rotate l_b)
    "rr" -> State (rotate l_a) (rotate l_b)

execute (State l_a l_b) op = case op of
    "rra" -> State (reverse l_a) l_b
    "rrb" -> State l_a (reverse l_b)
    "rrr" -> State (reverse l_a) (reverse l_b)
    _ -> error "Invalid operation"


main :: IO ()
main = do
    l_a <- fmap read <$> getArgs
    if null l_a then exitWith (ExitFailure 84)
    else do
        ops <- words <$> getLine
        let (State l_a' l_b') = foldl execute (State l_a []) ops
        putStrLn $ case isSorted l_a' of
            True -> "OK"
            False -> "KO: " ++ show (l_a', l_b')
