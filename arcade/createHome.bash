##################################################################################################
# #  Ce script bash (si je puis me permettre) génère un fichier txt pour pouvoir le récupérer  # #
# #  est générer le menu home à l'aide des informations qui sont présentes dans ce fichier.    # #
##################################################################################################

echo ".text" > src/Games/Home/home.txt ###TEXT###
echo "Arcade" >> src/Games/Home/home.txt
echo "[Commands]" >> src/Games/Home/home.txt
echo "[F5] : Previous library" >> src/Games/Home/home.txt
echo "[F6] : Next library" >> src/Games/Home/home.txt
echo "[F2] : Launch Nibbler" >> src/Games/Home/home.txt
echo "[F4] : Launch Snake" >> src/Games/Home/home.txt
echo "[Space] : Pause" >> src/Games/Home/home.txt
echo "[Suppr] : Leave" >> src/Games/Home/home.txt
echo "Game List:" >> src/Games/Home/home.txt
echo "Nibbler" >> src/Games/Home/home.txt
echo "Snake" >> src/Games/Home/home.txt

echo ".coordsText" >> src/Games/Home/home.txt ###TEXT COORDS###
echo "75 0" >> src/Games/Home/home.txt
echo "5 31" >> src/Games/Home/home.txt
echo "1 33" >> src/Games/Home/home.txt
echo "1 34" >> src/Games/Home/home.txt
echo "1 36" >> src/Games/Home/home.txt
echo "1 37" >> src/Games/Home/home.txt
echo "1 39" >> src/Games/Home/home.txt
echo "1 40" >> src/Games/Home/home.txt
echo "75 22" >> src/Games/Home/home.txt
echo "77 23" >> src/Games/Home/home.txt
echo "77 24" >> src/Games/Home/home.txt

echo ".sprite" >> src/Games/Home/home.txt ###SPRITE LOAD###
echo "src/Graphics/Sprites/fond_arcade.png" >> src/Games/Home/home.txt

echo ".coordsSprite" >> src/Games/Home/home.txt ###SPRITE COORDS###
echo "0 0" >> src/Games/Home/home.txt