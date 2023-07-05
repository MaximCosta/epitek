{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-MPL-3-1-PDGD01-maxim.costa [WSL: Ubuntu]
-- File description:
-- day 02
-}

import System.Environment (getArgs)
import System.Exit

myElem :: Eq a => a -> [a] -> Bool
myElem x = foldr (\ y -> (||) (x == y)) False

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:_) 0 = Just x
safeNth (_:xs) n = safeNth xs (n-1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc = fmap succ

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup x ((k,v):xs)
  | x == k    = Just v
  | otherwise = myLookup x xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo f mx my = mx >>= (\x -> my >>= (Just . f x))

readInt :: String -> Maybe Int
readInt str = case reads str of
  [(n, "")] -> Just n
  _ -> Nothing

getLineLength :: IO Int
getLineLength = length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength s = putStrLn s >> return (length s)

printBox :: Int -> IO ()
printBox n =
  let topBottom = "+" ++ replicate (2 * n - 2) '-' ++ "+"
      middle = "|" ++ replicate (2 * n - 2) ' ' ++ "|"
  in putStrLn topBottom >> mapM_ (putStrLn . const middle) [1..n-2]
     >> putStrLn topBottom

concatLines :: Int -> IO String
concatLines n = do
  lines <- mapM (const getLine) [1..n]
  return (concat lines)

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine

main :: IO ()
main = print 42
