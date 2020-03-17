
import threading
import time
import sys

morse = dict((
('A', '.-'),
('B', '-...'),
('C', '-.-.'),
('D', '-..'),
('E', '.'),
('F', '..-.'),
('G', '--.'),
('H', '....'),
('I', '..'),
('J', '.---'),
('K', '-.-'),
('L', '.-..'),
('M', '--'),
('N', '-.'),
('O', '---'),
('P', '.--.'),
('Q', '--.-'),
('R', '.-.'),
('S', '...'),
('T', '-'),
('U', '..-'),
('V', '...-'),
('W', '.--'),
('X', '-..-'),
('Y', '-.--'),
('Z', '--..'),
('1', '.----'),
('2', '..---'),
('3', '...--'),
('4', '....-'),
('5', '.....'),
('6', '-....'),
('7', '--...'),
('8', '---..'),
('9', '----.'),
('0', '-----'),
(' ', 3 )))

class send(threading.Thread):
    def __init__(self, LookedUpMorse):
        super(send, self).__init__()
        self.LookedUpMorse = LookedUpMorse

    def run(self):
        LookedUpMorse = morse[char]
        MorseLen = len(morse[char])
        MorseIndex = 0
        # for MorseIndex in range(0,MorseLen-1):
        while (MorseIndex < MorseLen):
            print("\nsending %s" % LookedUpMorse[MorseIndex])
            # sys.stdout.flush()
            MorseIndex += 1
# def worker(number):
#     print ('I am thread: ' + str(number) + '\n')

def space(NoOfUnits):
    Units = 1
    SleepyTime = NoOfUnits * Units
    Key=0
    print("sleeping")
    time.sleep(SleepyTime)
    print("awake")
    Key=1


def FillBuffer():
    getchar

WpM = 20
CharPW = 5
SpacePW = 1
UnitsPSpace = 3
UnitPDot = 1
UnitPDash = 3
UnitPInterChar = 1

DotPC = 2 * ( UnitPDot + UnitPInterChar ) 
DashPC = 2 * ( UnitPDash + UnitPInterChar ) 

UnitsPW = (DotPC + DashPC )* CharPW + SpacePW * UnitsPSpace 
UnitsPM = UnitsPW * 20 
UnitsPS = UnitsPM / 60 

mSPUnit = float( 1/UnitsPS )

#print('Calc Time: %-6.4f' % mSPUnit )

Message = 'He llo World'

for char in Message.upper():
    # if ( char == ' '):
    #     print('space %s' % char)
    # else:
    if (isinstance(morse[char],int)):
        # print('found number')
        # print('delay %d' % morse[char])
        # thread_list = []
        # for i in range(4):
        #     thread = threading.Thread(target=worker, args=(i,))
        #     thread_list.append(thread)
        #     thread.start()
        thread = threading.Thread(target=space, args=(morse[char],))
        thread.start()
    else:
        time.sleep(.05)
        # sys.stdout.flush()
        # print('morse(char) %s' % morse[char])
        # sys.stdout.flush()
        thread = send(morse[char])
        thread.start()
    
