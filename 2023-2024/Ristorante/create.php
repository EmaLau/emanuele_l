<?php

$conn = mysqli_connect("127.0.0.1", "root", "", "ristorante");

if($conn === false){
    die("ERRORE :" . mysqli_connect_error());
}

$id = $_REQUEST['id'];


$sql = "DELETE FROM camerieri WHERE id_cameriere='$id'";
if(mysqli_query($conn, $sql)){
    echo "<h3>rimosso con successo</h3>";
    echo nl2br("\n$id");
}else{
    echo "ERRORE" . mysqli_error($conn);
}
mysqli_close($conn);
