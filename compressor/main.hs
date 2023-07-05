import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(..))
import Control.Monad (when)
import Data.List (minimumBy, groupBy, sortOn)
import Data.Function (on)
import Text.Read (readMaybe)

type Point = (Int, Int)
type Color = (Int, Int, Int)
type Pixel = (Point, Color)
type Cluster = (Color, [Pixel])

main :: IO ()
main = do
    args <- getArgs
    when (length args /= 6 || args !! 0 /= "-n" || args !! 2 /= "-l" || args !! 4 /= "-f") $ do
        putStrLn "USAGE: ./imageCompressor -n N -l L -f F"
        putStrLn "N number of colors in the final image"
        putStrLn "L convergence limit"
        putStrLn "F path to the file containing the colors of the pixels"
        exitWith (ExitFailure 84)

    let n = readMaybe (args !! 1) :: Maybe Int
        l = readMaybe (args !! 3) :: Maybe Double
    case (n, l) of
        (Just n, Just l) -> processFile n l (args !! 5)
        _ -> exitWith (ExitFailure 84)

processFile :: Int -> Double -> FilePath -> IO ()
processFile n l path = do
    content <- readFile path
    case parsePixels content of
        Just pixels -> do
            clusters <- kMeans n l pixels
            putStrLn $ formatClusters clusters
        Nothing -> exitWith (ExitFailure 84)

parsePixels :: String -> Maybe [Pixel]
parsePixels = undefined

euclideanDistance :: Color -> Color -> Double
euclideanDistance = undefined

kMeans :: Int -> Double -> [Pixel] -> IO [Cluster]
kMeans = undefined

formatClusters :: [Cluster] -> String
formatClusters = undefined
