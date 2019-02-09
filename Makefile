demo.exe: Grid/Grid.o Grid/Team/Team.o Grid/Gang/Gang.o Item/Armor.o Item/Item.o Item/Potion.o Item/Weapon.o Living/Hero/Hero.o Living/Hero/Paladin.o Living/Hero/Sorcerer.o Living/Hero/Warrior.o Living/Living.o Living/Monster/Dragon.o Living/Monster/Exoskeleton.o Living/Monster/Monster.o Living/Monster/Spirit.o main.o Spell/FireSpell.o Spell/IceSpell.o Spell/LightingSpell.o Spell/Spell.o Grid/Block/Block.o Grid/Block/CommonBlock.o Grid/Block/Market.o Grid/Block/NonAccessibleBlock.o Tools/scan_number.o
	g++ -o demo Grid/Grid.o Grid/Team/Team.o Grid/Gang/Gang.o Item/Armor.o Item/Item.o Item/Potion.o Item/Weapon.o Living/Hero/Hero.o Living/Hero/Paladin.o Living/Hero/Sorcerer.o Living/Hero/Warrior.o Living/Living.o Living/Monster/Dragon.o Living/Monster/Exoskeleton.o Living/Monster/Monster.o Living/Monster/Spirit.o main.o Spell/FireSpell.o Spell/IceSpell.o Spell/LightingSpell.o Spell/Spell.o Grid/Block/Block.o Grid/Block/CommonBlock.o Grid/Block/Market.o Grid/Block/NonAccessibleBlock.o Tools/scan_number.o

Grid/Grid.o : Grid/Grid.cpp
	g++ -c Grid/Grid.cpp -o Grid/Grid.o

Grid/Team/Team.o : Grid/Team/Team.cpp
	g++ -c Grid/Team/Team.cpp -o Grid/Team/Team.o

Grid/Gang/Gang.o : Grid/Gang/Gang.cpp
	g++ -c Grid/Gang/Gang.cpp -o Grid/Gang/Gang.o

Item/Armor.o : Item/Armor.cpp
	g++ -c Item/Armor.cpp -o Item/Armor.o

Item/Item.o : Item/Item.cpp
	g++ -c Item/Item.cpp -o Item/Item.o

Item/Potion.o : Item/Potion.cpp
	g++ -c Item/Potion.cpp -o Item/Potion.o

Item/Weapon.o : Item/Weapon.cpp
	g++ -c Item/Weapon.cpp -o Item/Weapon.o

Living/Hero/Hero.o : Living/Hero/Hero.cpp
	g++ -c Living/Hero/Hero.cpp -o Living/Hero/Hero.o

Living/Hero/Paladin.o : Living/Hero/Paladin.cpp
	g++ -c Living/Hero/Paladin.cpp -o Living/Hero/Paladin.o

Living/Hero/Sorcerer.o : Living/Hero/Sorcerer.cpp
	g++ -c Living/Hero/Sorcerer.cpp -o Living/Hero/Sorcerer.o

Living/Hero/Warrior.o : Living/Hero/Warrior.cpp
	g++ -c Living/Hero/Warrior.cpp -o Living/Hero/Warrior.o

Living/Living.o : Living/Living.cpp
	g++ -c Living/Living.cpp -o Living/Living.o

Living/Monster/Dragon.o : Living/Monster/Dragon.cpp
	g++ -c Living/Monster/Dragon.cpp -o Living/Monster/Dragon.o 

Living/Monster/Exoskeleton.o : Living/Monster/Exoskeleton.cpp
	g++ -c Living/Monster/Exoskeleton.cpp -o Living/Monster/Exoskeleton.o

Living/Monster/Monster.o : Living/Monster/Monster.cpp
	g++ -c Living/Monster/Monster.cpp -o Living/Monster/Monster.o

Living/Monster/Spirit.o : Living/Monster/Spirit.cpp
	g++ -c Living/Monster/Spirit.cpp -o Living/Monster/Spirit.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

Spell/FireSpell.o : Spell/FireSpell.cpp
	g++ -c Spell/FireSpell.cpp -o Spell/FireSpell.o

Spell/IceSpell.o : Spell/IceSpell.cpp
	g++ -c Spell/IceSpell.cpp  -o Spell/IceSpell.o

Spell/LightingSpell.o : Spell/LightingSpell.cpp
	g++ -c Spell/LightingSpell.cpp -o Spell/LightingSpell.o

Spell/Spell.o : Spell/Spell.cpp
	g++ -c Spell/Spell.cpp -o Spell/Spell.o

Grid/Block/Block.o : Grid/Block/Block.cpp
	g++ -c Grid/Block/Block.cpp -o Grid/Block/Block.o

Grid/Block/CommonBlock.o : Grid/Block/CommonBlock.cpp
	g++ -c Grid/Block/CommonBlock.cpp -o Grid/Block/CommonBlock.o

Grid/Block/Market.o : Grid/Block/Market.cpp
	g++ -c Grid/Block/Market.cpp -o Grid/Block/Market.o

Grid/Block/NonAccessibleBlock.o : Grid/Block/NonAccessibleBlock.cpp
	g++ -c Grid/Block/NonAccessibleBlock.cpp -o Grid/Block/NonAccessibleBlock.o

Tools/scan_number.o : Tools/scan_number.cpp
	g++ -c Tools/scan_number.cpp -o Tools/scan_number.o

clean:
	rm demo Grid/Grid.o Grid/Team/Team.o Grid/Gang/Gang.o Item/Armor.o Item/Item.o Item/Potion.o Item/Weapon.o Living/Hero/Hero.o Living/Hero/Paladin.o Living/Hero/Sorcerer.o Living/Hero/Warrior.o Living/Living.o Living/Monster/Dragon.o Living/Monster/Exoskeleton.o Living/Monster/Monster.o Living/Monster/Spirit.o main.o Spell/FireSpell.o Spell/IceSpell.o Spell/LightingSpell.o Spell/Spell.o Grid/Block/Block.o Grid/Block/CommonBlock.o Grid/Block/Market.o Grid/Block/NonAccessibleBlock.o Tools/scan_number.o
