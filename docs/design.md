assumptions:
    1. the config file is expected to be correct or else the game will have undefined behaviour 
    2. as the humans perceive the snakes and ladder game, this is not a 2d grid, this is a single line array with same configs ( makes much sense)
    3. current design does not include code saftey measures, meaning complier flags like [[nodiscard]] are still not in place
    4. Complete deconstructors are not in place, there is one for board tho, since it creates a lot of things
    5. The test cases build are referenced with the help of chatGPT, this is not a matter of cheating, but just to pace up my coding speed, since the complete design and test cases are mine, chatGPT merely provided test cases written.
    6. -W warning flags are not high in this code, but rest assured the code is fully complaint with c++17 

- player
- objects 
    - snakes 
    - ladder
    - croc
    - mine
- cell 
- board 
- game_simulator 

- random_dice
- logger 
- reader 


- player
    - name 
    - position 
    - is_mined // need better way 

- objects 
    - name :: ObjectType
    - start
    - end 

            - snakes 
            - ladder 
            - croc
            - mine 
                - activate player

- cell
    - player
    - isWin
    - object

- board 
    - cells
    - players
    - initialization 
    - movement


- simulator 
    - dicing 
    - logger 
    - board 

