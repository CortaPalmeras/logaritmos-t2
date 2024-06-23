
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

df=pd.read_csv("dijkstra.csv")


def regresion(X,Y):
    modelo=LinearRegression(X,Y)
    y_pred=modelo.predict(X)
    plt.scatter(X, Y, color='blue', label='Datos reales')
    plt.plot(X, y_pred, color='red', label='Línea de regresión')
    plt.xlabel('Numero de aristas')
    plt.ylabel('Tiempos')
    plt.title(f'Regresión lineal para vertice={df.iloc[0,0]}')
    plt.legend()
    plt.savefig()
    plt.close()


def crearGrafico(df):
    X=df["cantidad_aristas"]
    Y1=df["t_con_fib"]
    Y2=df["t_con_heap"]
    regresion(X,Y1)
    regresion(X,Y2)


for i in range(10,17,2):
    df1=df[df["cantidad_nodos"]==i]
    crearGrafico(df1)
