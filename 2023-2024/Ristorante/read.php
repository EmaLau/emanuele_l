<?php

$conn = mysqli_connect("127.0.0.1", "root", "", "ristorante");

if($conn === false){
    die("ERRORE :" . mysqli_connect_error());
}

$nome = $_REQUEST['nome'];
$cognome = $_REQUEST['cognome'];

$sql = "INSERT INTO camerieri (nome, cognome) VALUES ('$nome', '$cognome')";
if(mysqli_query($conn, $sql)){
    echo "<h3>Dati messi con successo</h3>";
    echo nl2br("\n$nome \n$cognome");
}else{
    echo "ERRORE" . mysqli_error($conn);
}
mysqli_close($conn);
