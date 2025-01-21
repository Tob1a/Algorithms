import matplotlib.pyplot as plt
# e' un backend che tanti linguaggi di programmazione c'e' 

with open("report.txt") as file: #with serve per rinominare un operazione with operation as ciao
    lines = file.readlines()

algos = ["INSERTION", "MERGE"]

#split interrompe la lines[0] in tanti numeri
x_data = list(map(int,lines[0].split())) #map trasforma un elemento in un altro esempio stringa in intero
y_data= [ list(map(float, line.split())) for line in lines[1:]]#il lines[1:] vuol dire che prendo in considerazione dal 1 alla fine
#list serve per

for i, time in enumerate(y_data):
    #tieni in mente i e time mentre fai il ciclo for quindi i=0  time=e-3*1.2 o che ne so  ,i=1 time =...
    plt.plot(x_data,time,label=algos[i])
plt.ylabel("Size")
plt.ylabel("Elapsed time [s]")
plt.title("Sorting experiments")
plt.legend()
plt.show()
