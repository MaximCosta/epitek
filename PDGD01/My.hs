{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-MPL-3-1-PDGD01-maxim.costa [WSL: Ubuntu]
-- File description:
-- My
-}

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x = if x < 0 then -x else x

myMin :: Int -> Int -> Int
myMin x y = if x < y then x else y

myMax :: Int -> Int -> Int
myMax x y = if x > y then x else y

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a, b, c)
myTruple x y z = (x, y, z)

myFst :: (a, b) -> a
myFst (x, _) = x

mySnd :: (a, b) -> b
mySnd (_, y) = y

mySwap :: (a, b) -> (b, a)
mySwap (x, y) = (y, x)

myHead :: [a] -> a
myHead [] = error "The list is empty"
myHead (x:_) = x

myTail :: [a] -> [a]
myTail [] = error "The list is empty"
myTail (_:xs) = xs

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth [] _ = error "Index out of bounds"
myNth (x:_) 0 = x
myNth (_:xs) n = myNth xs (n - 1)

myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake 0 _ = []
myTake n (x:xs)
  | n > myLength (x:xs) = x:xs
  | otherwise = x : myTake (n - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop 0 xs = xs
myDrop n (x:xs)
  | n > myLength (x:xs) = []
  | otherwise = myDrop (n - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] ys = ys
myAppend (x:xs) ys = x : myAppend xs ys

myReverse :: [a] -> [a]
myReverse xs = myReverse' xs []
  where
    myReverse' :: [a] -> [a] -> [a]
    myReverse' [] acc = acc
    myReverse' (x:xs) acc = myReverse' xs (x:acc)

myInit :: [a] -> [a]
myInit [] = error "The list is empty"
myInit [_] = []
myInit (x:xs) = x : myInit xs

myLast :: [a] -> a
myLast [] = error "The list is empty"
myLast [x] = x
myLast (_:xs) = myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y):xs) = (x:xs', y:ys')
  where
    (xs', ys') = myUnzip xs

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (x:xs) = f x : myMap f xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter p (x:xs) = if p x then x : myFilter p xs else myFilter p xs
