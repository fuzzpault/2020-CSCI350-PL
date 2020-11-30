-- Paul Talaga
-- CSCI 355 Final Starter Code
--
-- Load this like: $ ghci final.hs
-- Then do :r to reload final.hs if you change it.


data Node a = Null | N a (Node a) (Node a) deriving (Show, Eq)

tree1 = N 8 Null Null
tree2 = N 8 (N 10 Null Null) Null
tree3 = N 8 (N 10 (N 10 Null (N 10 Null Null)) Null) (N 10 Null Null)
tree4 = N 12 (N 6 (N 2 Null Null) (N 8 Null Null)) (N 18 Null Null)
tree5 = N 8 (N 10 (N 10 Null (N 10 Null Null)) Null) (N 10 Null Null)

makeLine :: Char -> Int -> String
makeLine _ 0 = ""
makeLine c n = c: (makeLine c (n-1))

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

-- 

