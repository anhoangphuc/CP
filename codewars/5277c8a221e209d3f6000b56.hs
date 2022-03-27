module CodeWars where

isPair :: Char -> Char -> Bool 
isPair x y
    | x == '(' && y == ')' = True
    | x == '[' && y == ']' = True
    | x == '{' && y == '}' = True
    | otherwise = False 

isOpen x
    | x == '(' = True
    | x == '[' = True
    | x == '{' = True
    | otherwise  = False 

checkValid :: String -> String -> Bool 
validBraces :: String -> Bool 
validBraces xs = checkValid "" xs
checkValid "" "" = True
checkValid "" (hs:ts)
    | isOpen hs = checkValid (hs:"") ts
    | otherwise = False 
checkValid (hstack:_) "" = False 
checkValid (hstack:tstack) (hs:ts)
    | isPair hstack hs = checkValid tstack ts
    | isOpen hs = checkValid (hs : (hstack:tstack)) ts
    | otherwise  = False
