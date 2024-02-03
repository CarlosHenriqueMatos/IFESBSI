from time import sleep
from threading import Thread

listTest = ["Carlos","Carlos I","Carlos II", "Carlos III", "Carlos IV"]

class MyClass(Thread):
    def __init__(self,value):
        print("Constructor called")
        self.kid=value
        Thread.__init__(self)

    def compression(self) -> None:
        print("Video compression code")

    def run(self) -> None:
        a = 10
        b = 20
        self.compression()
        if self.kid:
            print("Suitable for kids")
        for vid in listTest:
            print(f"{vid} started uploading...")
            sleep(1)
            print(f"{vid} uploaded.")
        self.temp=a+b
t1=MyClass(True)
t1.start()
sleep(10)#time necessary to tempo be created
print("Result",t1.temp)
for i in range(4):
    sleep(4)
    print("Checking copyrights")