import mysql.connector
import pandas as pd
import numpy as np

# Connessione al database
conn = mysql.connector.connect(
    host="127.0.0.1",
    user="root",
    password="",
    database="Noleggio"
)
cursor = conn.cursor()

# Percorso del file CSV
csv_file_path = "noleggi.csv"

# Carica i dati nella tabella Clienti
df_clienti = pd.read_csv(csv_file_path)
df_clienti.fillna(value=pd.NA, inplace=True)  # Sostituisci i valori NaN con None
for _, row in df_clienti.iterrows():
    cursor.execute("""
        INSERT INTO Clienti (cognome, nome, data_nascita, data_rilascio_patente, num_cell, mail)
        VALUES (%s, %s, %s, %s, %s, %s)
    """, (row['cognome'], row['nome'], row['data_nascita'], row['data_rilas_patente'], row['num_cell'], row['mail']))
conn.commit()

# Carica i dati nella tabella Auto
df_auto = pd.read_csv(csv_file_path)
df_auto.fillna(value=pd.NA, inplace=True)  # Sostituisci i valori NaN con None
for _, row in df_auto.iterrows():
    costo_per_km = None if pd.isna(row['costo_per_km']) else float(str(row['costo_per_km']).replace(',', '.'))
    cursor.execute("""
        INSERT INTO Auto (targa, marca, modello, tipo_alimentazione, data_revisione, costo_per_km)
        VALUES (%s, %s, %s, %s, %s, %s)
    """, (row['targa'], row['marca'], row['modello'], row['tipo_alimentazione'], row['data_revisione'], costo_per_km))
conn.commit()

# Carica i dati nella tabella Noleggi
df_noleggi = pd.read_csv(csv_file_path)
df_noleggi.fillna(value=0, inplace=True)  # Sostituisci i valori NaN con 0
for _, row in df_noleggi.iterrows():
    cursor.execute("""
        INSERT INTO Noleggi (id_cliente, id_auto, data_inizio_noleggio, data_fine_noleggio, km_effettuati)
        VALUES (%s, %s, %s, %s, %s)
    """, (row['id_cliente'], row['id_auto'], row['data_inizio_noleggio'], row['data_fine_noleggio'], row['km_effettuati']))
conn.commit()

# Chiudi la connessione al database
cursor.close()
conn.close()
