-- TASK 13
data Tree a = Leaf | Node a (Tree a) (Tree a)
  deriving (Eq, Show)

-- TASK 14
size :: Tree a -> Int
size Leaf = 0
size (Node _ left right) = 1 + size left + size right

-- TASK 15
height :: Tree a -> Int
height Leaf = 0
height (Node _ left right) = 1 + max (height left) (height right)

-- TASK 16
sumTree :: Tree Int -> Int
sumTree Leaf = 0
sumTree (Node value left right) = value + sumTree left + sumTree right

-- TASK 17
nbLeaves :: Tree a -> Int
nbLeaves Leaf = 1
nbLeaves (Node _ left right) = nbLeaves left + nbLeaves right

-- TASK 18
mapTree :: (a -> b) -> Tree a -> Tree b
mapTree _ Leaf = Leaf
mapTree f (Node value left right) = Node (f value) (mapTree f left) (mapTree f right)

-- TASK 19
tfold :: (a -> b -> b -> b) -> b -> Tree a -> b
tfold _ acc Leaf = acc
tfold f acc (Node value left right) = f value (tfold f acc left) (tfold f acc right)

-- TASK 20
size' :: Tree a -> Int
size' = tfold (\_ left right -> 1 + left + right) 0

height' :: Tree a -> Int
height' = tfold (\_ left right -> 1 + max left right) 0

sumTree' :: Tree Int -> Int
sumTree' = tfold (\value left right -> value + left + right) 0

nbLeaves' :: Tree a -> Int
nbLeaves' = tfold (\_ left right -> left + right) 1

mapTree' :: (a -> b) -> Tree a -> Tree b
mapTree' f = tfold (\value left right -> Node (f value) left right) Leaf
