import json, matplotlib.pyplot as plt

with open("../source/vector.json") as vectorFile:
    jsonObject = json.load(vectorFile)
    vectorFile.close()

nom1 = '2 Dimensiones'
nom2 = '5 Dimensiones'
nom3 = '10 Dimensiones'
nom4 = '15 Dimensiones'
nom5 = '20 Dimensiones'
nom6 = '25 Dimensiones'

v2 = jsonObject[nom1]
v5 = jsonObject[nom2]
v10 = jsonObject[nom3]
v15 = jsonObject[nom4]
v20 = jsonObject[nom5]
v25 = jsonObject[nom6]

fig = plt.gcf()

fig.set_size_inches(15.5,7.5)

plt.subplot(231)
plt.plot(v2)
plt.title(nom1)

plt.subplot(232)
plt.plot(v5)
plt.title(nom2)

plt.subplot(233)
plt.plot(v10)
plt.title(nom3)

plt.subplot(234)
plt.plot(v15)
plt.title(nom4)

plt.subplot(235)
plt.plot(v20)
plt.title(nom5)

plt.subplot(236)
plt.plot(v25)
plt.title(nom6)

fig.savefig("../images/graficas.png", dpi=100)

plt.show()

fig2, ax = plt.subplots()
ax.plot(v2, label=nom1)
ax.plot(v5, label=nom2)
ax.plot(v10, label=nom3)
ax.plot(v15, label=nom4)
ax.plot(v20, label=nom5)
ax.plot(v25, label=nom6)
ax.set_title("Comparacion Dimensiones")
ax.legend()
fig2.savefig("../images/graficasJuntas.png", dpi=100)
plt.show()