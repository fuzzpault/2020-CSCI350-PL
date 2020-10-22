-- Paul Talaga
-- CSCI 355 Class Demo - Oct 21, 2020
--
-- Load this like: $ ghci demo.hs
-- Then do :r to reload demo.hs if you change it.
-- Or 

-- A function to add three values
add :: Int -> Int -> Int -> Int
add a b c = a + b + c + 1 

myrepeat :: String -> String
myrepeat s = s ++ s

first :: [Int] -> [Int]
first (x:y:xs) = x
first [] = [4]

-- Decreasing values in a list
counter :: Int -> [Int]
counter 0 = []
counter n = n:(counter (n-1) )

-- Increasing values in a list
countUp :: Int -> [Int]
countUp 0 = []
countUp n = (countUp (n-1) ) ++ [n] 

-- A list of n values, but using a secondary recursive function
helperCount a b | a == b = []
                | otherwise =  [a] ++ (helperCount a (b + 1))
                
countUp2 :: Int -> [Int]
countUp2 n = helperCount n 0


-- Put the \n character for a new line
-- Send it to putStrLn to display with the newlines
-- Ex: *Main> putStrLn (makeLine 5)
makeLine :: Int -> String
makeLine 0 = ">"
makeLine n = "-" ++ (makeLine (n-1) ) ++ "\n"


-- Example of using guards, note the syntax
whatGrade :: Int -> String -> String
whatGrade grade m | grade < 65 = "F" ++ m
                | grade < 75 = "D" ++ m
                | grade < 98 = "C" ++ m
                | otherwise = "A" ++ m
                


bob = [('g',6), ('j',9)]