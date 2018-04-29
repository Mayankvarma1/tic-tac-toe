theBoard={'Top_l':' ','Top_m':' ','Top_r':' ','Mid_l':' ','Mid_m':' ','Mid_r':' ','Low_l':' ','Low_m':' ','Low_r':' '}
def printBoard(board):
    print(board['Top_l']+'|'+board['Top_m']+'|'+board['Top_r'])
    print('-+-+-')
    print(board['Mid_l']+'|'+board['Mid_m']+'|'+board['Mid_r'])
    print('-+-+-')
    print(board['Low_l']+'|'+board['Low_m']+'|'+board['Low_r'])
turn='X'
flag=0
for i in range(9):
    printBoard(theBoard)
    if i>4:
        board=theBoard
        if(board['Top_l']!=' ' and board['Top_l']==board['Top_m'] and board['Top_m']==board['Top_r']):
            print(turn+" WINS")
            flag=1
            break
        elif(board['Mid_l']!=' ' and board['Mid_l']==board['Mid_m'] and board['Mid_m']==board['Mid_r']):
            print(turn+" WINS")
            flag=1
            break
        elif(board['Low_l']!=' ' and board['Low_l']==board['Low_m'] and board['Low_m']==board['Low_r']):
            print(turn+" WINS")
            flag=1
            break
        elif(board['Top_l']!=' ' and board['Top_l']==board['Mid_m'] and board['Mid_m']==board['Low_r']):
            print(turn+" WINS")
            flag=1
            break
        elif(board['Low_l']!=' ' and board['Low_l']==board['Mid_m'] and board['Mid_m']==board['Top_r']):
            print(turn+" WINS")
            flag=1
            break
        elif(board['Top_l']!=' ' and board['Top_l']==board['Mid_l'] and board['Mid_l']==board['Low_l']):
            print(turn+" WINS")
            flag=1
            break
        elif(board['Top_m']!=' ' and board['Top_m']==board['Mid_m'] and board['Mid_m']==board['Low_m']):
            print(turn+" WINS")
            flag=1
            break
        elif(board['Top_r']!=' ' and board['Top_r']==board['Mid_r'] and board['Mid_r']==board['Low_r']):
            print(turn+" WINS")
            flag=1
            break
    print('TURN FOR '+turn+'. Move on which space?\n')
    move=input()
    m=0
    while m==0:
        if theBoard[move]!=' ':
            print("Invalid input, please enter again. Move on which space?\n")
            move=input()
        else:
            m=1
    theBoard[move]=turn
    if turn=='X':
        turn='O'
    else:
        turn='X'
if flag==0:
    printBoard(theBoard)