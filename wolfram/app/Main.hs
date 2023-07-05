--
-- EPITECH PROJECT, 2023
-- wolfram [WSL: Ubuntu]
-- File description:
-- Main
--

module Main (main) where
import System.Exit (exitWith, ExitCode(ExitFailure))

import Lib

main :: IO ()
main = someFunc >> exitWith (ExitFailure 84)