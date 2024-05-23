assumptions:
    1. the config file is expected to be correct or else the game will have undefined behaviour 
    2. as the humans perceive the snakes and ladder game, this is not a 2d grid, this is a single line array with same configs ( makes much sense)
    3.

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
    - name 
    - direction (+,-)
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


    

