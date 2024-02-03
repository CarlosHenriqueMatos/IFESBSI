from threading import Thread
# source https://www.youtube.com/watch?v=jkwhht2gXB8&list=PLI4OVrCFuY57b_16D8xs7-hmABHncVD_w&index=4
def threading_informations():
    print(Thread.current_thread())
    print(Thread.current_thread().name)
    print(Thread.current_thread().ident)
    print(Thread.current_thread().is_alive())
class Example:
    def display(self,n,msg):
        for i in range(n):
            print(msg)
    def display_unique(self, x):
        for i in range(x):
            print(i)

e1 = Example()

t1 = Thread(target=e1.display,args=(30,"Hello")) #new thread here
t2 = Thread(target=e1.display_unique,args=(30,))
t3 = Thread(target=e1.display_unique, kwargs={'x':40})
t4 = Thread(target=e1.display, kwargs={"n":30,"msg":"Carlos"})

t1.start()
t2.start()
t3.start()
t4.start()

