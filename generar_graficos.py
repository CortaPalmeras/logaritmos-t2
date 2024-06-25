import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler
import os

df=pd.read_csv("dijkstra.csv")

df["cantidad_nodos"]=pd.to_numeric(df["cantidad_nodos"], errors='coerce')
df["cantidad_aristas"]=pd.to_numeric(df["cantidad_aristas"],errors='coerce')

os.makedirs("out", exist_ok = True)

def regresion(X,Y,titulo,filename):
    if X.empty or Y.empty:
        print(f"No hay datos para {titulo}, no se creará el gráfico.")
        return
    
    X=X.values.reshape(-1,1)
    
    modelo=LinearRegression()
    modelo.fit(X, Y)
    y_pred=modelo.predict(X)
    
    pendiente=modelo.coef_[0]
    intercepcion=modelo.intercept_
    
    print(f"Pendiente: {pendiente}, Intercepción: {intercepcion} para {titulo}")

    plt.scatter(X,Y,color='blue',alpha=0.5,label='Datos reales')
    plt.plot(X,y_pred,color='red',label='Línea de regresión')
    plt.xlabel('Número de aristas')
    plt.ylabel('Tiempos en milisegundos')
    plt.title(f"{titulo}\nPendiente: {pendiente}")
    plt.legend()
    plt.savefig(filename)
    plt.close()

def crearGrafico(df,vertice):
    X=df["cantidad_aristas"]
    Y1=df["t_con_fib"]
    Y2=df["t_con_heap"]
    
    regresion(X,Y1,f'Regresión lineal para nodos={vertice} (con fib)', f'out/regresion_fib_{vertice}.png')
    regresion(X,Y2,f'Regresión lineal para nodos={vertice} (con heap)', f'out/regresion_heap_{vertice}.png')

df["cantidad_aristas"]=df["cantidad_aristas"].apply(lambda x:2**x)
df["cantidad_nodos"]=df["cantidad_nodos"].apply(lambda x:2**x)

df["t_con_fib"]=df["t_con_fib"].apply(lambda x:x*1000)
df["t_con_heap"]=df["t_con_heap"].apply(lambda x:x*1000)

valores_nodos=[2**i for i in range(10,17)]

for valor in valores_nodos:
    df_filtrado=df[df["cantidad_nodos"]==valor]
    if not df_filtrado.empty:  
        crearGrafico(df_filtrado, valor)

