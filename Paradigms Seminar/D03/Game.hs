{-
-- EPITECH PROJECT, 2023
-- Game.hs
-- File description:
-- Pool Day 03
-}

data Item = Sword | Bow | MagicWand deriving (Eq)
data Mob = Mummy | Skeleton (Item) | Witch (Maybe Item) deriving (Eq)

instance Show Item where
  show Sword = "sword"
  show Bow = "bow"
  show MagicWand = "magic wand"

createMummy :: Mob
createMummy =  Mummy
createArcher :: Mob
createArcher = Skeleton (Bow)
createKnight :: Mob
createKnight = Skeleton (Sword)
createWitch :: Mob
createWitch = Witch (Nothing)
createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create i = case i of
  "mummy" -> Just createMummy
  "doomed archer" -> Just createArcher
  "dead knight" -> Just createKnight
  "witch" -> Just createWitch
  "sorceress" -> Just createSorceress
  i -> Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip a (Skeleton b) = Just (Skeleton a)
equip a (Witch b) = Just (Witch (Just a))

instance Show Mob where
  show Mummy = "mummy"
  show (Skeleton Bow) = "doomed archer"
  show (Skeleton Sword) = "dead knight"
  show (Skeleton x) = "skeleton holding a " ++ show x
  show (Witch Nothing) = "Witch"
  show (Witch (Just MagicWand)) = "sorceress"
  show (Witch (Just x)) = "witch holding a " ++ show x

class HasItem a where
  getItem :: a -> Maybe Item
  hasItem :: a -> Bool

instance HasItem Mob where
  hasItem Mummy = False
  hasItem (Skeleton a) = True
  hasItem (Witch Nothing) = False
  hasItem (Witch (Just a)) = True
  getItem Mummy = Nothing
  getItem (Skeleton a) = Just a
  getItem (Witch Nothing) = Nothing
  getItem (Witch (Just a)) = Just a
