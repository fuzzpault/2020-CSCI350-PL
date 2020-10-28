-- Paul Talaga
-- CSCI 355 Class Demo - Oct 28, 2020
--
-- Load this like: $ ghci demo.hs
-- Then do :r to reload demo.hs if you change it.

-- Send a picture to pretty and it will print it out with new lines.
pretty :: [String] -> IO ()
pretty x = putStrLn (prettyHelp x)

prettyHelp :: [String] -> String
prettyHelp [] = ""
prettyHelp (x:xs) = x ++ "\n" ++ prettyHelp xs


count :: (Eq a) => a -> [a] -> Int
--count :: Int -> [Int] -> Int
count _ [] = 0 
count a (x:xs) | a == x = 1 + count a xs
               | otherwise = count a xs
               
replaceAll :: (Eq a) => a -> a -> [a] -> [a]
replaceAll _ _ [] = []
replaceAll s r (x:xs) | s == x = r : (replaceAll s r xs)
                      | otherwise = x : (replaceAll s r xs)
              
                      
--replaceAll2 :: (Eq a) => a -> a -> [a] -> [a]
replaceAll2 :: Char-> Char -> [Char] -> [Char]
replaceAll2 _ _ [] = " MIDDLE "
replaceAll2 s r (x:xs) | s == x = [r] ++ (replaceAll2 s r xs) ++ [r]
                       | otherwise = [x] ++ (replaceAll2 s r xs) ++ [x]
                       
box3 = ["***","***", "***"]

makeLine :: Char -> Int -> String
makeLine _ 0 = ""
makeLine c n = c: (makeLine c (n-1))

boxHelper :: Int -> Int -> [String]
boxHelper 0 _ = []
boxHelper toGo width = (makeLine '*' width) : (boxHelper (toGo - 1) width)

box :: Int -> [String]
box n = boxHelper n n

----------------------------------------------------
data Node a = Null | N a (Node a) (Node a) deriving (Show, Eq)

tree1 = N 8 Null Null
tree2 = N 8 (N 10 Null Null) Null
tree3 = N 8 (N 10 (N 10 Null (N 10 Null Null)) Null) (N 10 Null Null)

-- Returns the number of nodes in the tree
numNodes :: Node a -> Int
numNodes Null = 0
numNodes (N _ left right) =  1 + (numNodes left) + (numNodes right)

-- Adds the value to an existing tree in a binary search tree manner
addValue :: (Ord a) => a -> Node a -> Node a
addValue v Null = N v Null Null
addValue v (N p left right) | v < p = (N p (addValue v left) right) 
                            | otherwise = (N p  left (addValue v right) )
                            
-- Creates a tree based on a list of values
toTree :: (Ord a) => [a] -> Node a
toTree [] = Null
toTree (x:xs) = addValue x (toTree xs)

prettyTreeHelp :: (Show a) => Node a -> Int -> String
prettyTreeHelp Null _ = ""
prettyTreeHelp (N v left right) n = (prettyTreeHelp right (n+5)) ++ (makeLine ' ' n) ++ (show v) ++ "\n" ++ (prettyTreeHelp left (n+5))

-- Print the tree out using indentation to show the shape
prettyTree :: (Show a) => Node a -> IO ()
prettyTree x = putStrLn (prettyTreeHelp x 0)
