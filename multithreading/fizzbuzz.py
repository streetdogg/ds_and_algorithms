#!/usr/bin/python
import threading
import sys

class buzzFizz:
    def __init__(self, num):
        self.num = num
        self.t1_t2 = threading.Event()
        self.t1_t3 = threading.Event()
        self.t1_t4 = threading.Event()

        self.t2_t1 = threading.Event()
        self.t3_t1 = threading.Event()
        self.t4_t1 = threading.Event()

        self.t1_t2.clear()
        self.t1_t3.clear()
        self.t1_t4.clear()

        self.t2_t1.clear()
        self.t3_t1.clear()
        self.t4_t1.clear()

    def run(self):
        t = []
        targets = [self.thread_2, self.thread_3, self.thread_4, self.thread_1]
        for i in range(4):
            t.append(threading.Thread(target=targets[i]))
            t[i].start()

        for i in range(4):
            t[i].join()

    def thread_1(self):
        # Let every one else read
        self.t1_t2.set()
        self.t1_t3.set()
        self.t1_t4.set()

        while True:
            # wait for every one else to signal that they are done
            # reading
            self.t2_t1.wait()
            self.t3_t1.wait()
            self.t4_t1.wait()

            self.num -= 1

            # clear the events being set previously
            self.t2_t1.clear()
            self.t3_t1.clear()
            self.t4_t1.clear()

            # Allow other threads to proceed
            self.t1_t2.set()
            self.t1_t3.set()
            self.t1_t4.set()

            if (self.num == 0):
                break

    def thread_2(self):
        while True:
            # Wait for thread 1 to signal updation of value
            self.t1_t2.wait()

            if (self.num % 3 == 0 and self.num % 5 != 0):
                print ("Buzz! {}".format(self.num))

            # clear the event being set previously
            self.t1_t2.clear()

            # allow thread 1 to proceed
            self.t2_t1.set()

            if (self.num == 0):
                break

    def thread_3(self):
        while True:
            # Wait for thread 1 to signal updation of value
            self.t1_t3.wait()

            if (self.num % 5 == 0 and self.num % 3 != 0):
                print ("Fizz! {}".format(self.num))

            # clear the event being set previously
            self.t1_t3.clear()
            self.t3_t1.set()

            if (self.num == 0):
                break

    def thread_4(self):
        while True:
            # Wait for thread 1 to signal updation of value
            self.t1_t4.wait()

            if (self.num % 3 == 0 and self.num % 5 == 0):
                print ("BuzzFizz! {}".format(self.num))

            # clear the event being set previously
            self.t1_t4.clear()

            # allow thread 1 to proceed
            self.t4_t1.set()

            if (self.num == 0):
                break

def main():
    if len(sys.argv) != 2:
        print ("usage: python3 fizzbuzz.py NUM")
        return

    num = int(sys.argv[1])
    bf = buzzFizz(num)
    bf.run()

if __name__ == "__main__":
    main()