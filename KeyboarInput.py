import sys, os, time
fd = sys.stdin.fileno()


while 1:
    try:
        c = sys.stdin.read(1)
        if c:
                print("Got character", repr(c))
    except:
        time.sleep(1)