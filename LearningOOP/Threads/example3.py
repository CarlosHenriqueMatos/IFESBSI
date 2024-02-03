from threading import Thread, current_thread, main_thread, active_count, enumerate, get_native_id
import os

def display():
    print(f"Native id of t1: {get_native_id}")
    print(f"Main thread details: {main_thread()}")
    for i in range(20):
        print("Hello World")
def show():
    for i in range(2):
        print("Welcome!")

t1 = Thread(target=display)
t2 = Thread(target=show)
t1.name="T1"    

print(f"Thread 1 is alive: {t1.is_alive()}")
t1.start()
t1.join()#only start another thread before finish these execution

print(f"Thread 1 is alive: {t1.is_alive()}")
print(f"Number of threads(active count): {active_count()}")
t2.start()
t2.join()
print(f"Number of threads(enumerate): {enumerate()}")

current_thread().name="Jay"
print(f"T1 ident: {t1.ident}")
print(f"T2 name: {t2.name}")
print(f"T2 native id: {t2.native_id}")
print(f"Pid: {os.getpid()}")
