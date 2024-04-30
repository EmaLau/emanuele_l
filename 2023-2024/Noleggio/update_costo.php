<?php
// Connessione al database
$servername = "127.0.0.1";
$username = "root";
$password = "";
$dbname = "Noleggio";

// Crea la connessione
$conn = new mysqli($servername, $username, $password, $dbname);

// Verifica la connessione
if ($conn->connect_error) {
    die("Connessione fallita: " . $conn->connect_error);
}

// Aggiornamento del 5% alla tariffa di noleggio delle auto
$alimentazione = $_POST['alimentazione'];
$sql = "UPDATE Auto SET costo_per_km = costo_per_km * 1.05 WHERE tipo_alimentazione = '$alimentazione'";

if ($conn->query($sql) === TRUE) {
    echo "Aggiornamento completato con successo.";
} else {
    echo "Errore durante l'aggiornamento: " . $conn->error;
}

// Chiudi la connessione al database
$conn->close();
?>