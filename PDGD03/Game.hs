{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-MPL-3-1-PDGD03-maxim.costa [WSL: Ubuntu]
-- File description:
-- Game
-}

-- TASK 01
data Item = Sword | Bow | MagicWand
  deriving (Eq)

-- TASK 03
instance Show Item where
  show Sword = "sword"
  show Bow = "bow"
  show MagicWand = "magic wand"

-- TASK 4
data Mob = Mummy | Skeleton Item | Witch (Maybe Item)
  deriving (Eq)

-- TASK 8
instance Show Mob where
  show Mummy = "mummy"
  show (Skeleton Bow) = "doomed archer"
  show (Skeleton Sword) = "dead knight"
  show (Skeleton item) = "skeleton holding a " ++ show item
  show (Witch Nothing) = "witch"
  show (Witch (Just MagicWand)) = "sorceress"
  show (Witch (Just item)) = "witch holding a " ++ show item

-- TASK 5
createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

-- TASK 6
create :: String -> Maybe Mob
create "mummy" = Just Mummy
create "doomed archer" = Just (Skeleton Bow)
create "dead knight" = Just (Skeleton Sword)
create "witch" = Just (Witch Nothing)
create "sorceress" = Just (Witch (Just MagicWand))
create _ = Nothing

-- TASK 7
equip :: Item -> Mob -> Maybe Mob
equip item (Skeleton _) = Just (Skeleton item)
equip item (Witch _) = Just (Witch (Just item))
equip _ Mummy = Nothing

-- TASK 9
class Attack a where
  attack :: a -> String

-- TASK 10
instance Attack Mob where
  attack Mummy = "mummy attack"
  attack (Skeleton _) = "skeleton attack"
  attack (Witch _) = "witch attack"

-- TASK 11
class (Attack a) => Defense a where
  defend :: a -> String

-- TASK 12
instance Defense Mob where
  defend Mummy = "mummy defend"
  defend (Skeleton _) = "skeleton defend"
  defend (Witch _) = "witch defend"