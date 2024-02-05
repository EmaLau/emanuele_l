<?php

$conn = mysqli_connect("127.0.0.1", "root", "", "ristorante");

if($conn === false){
    die("ERRORE :" . mysqli_connect_error());
}

$sql = "SELECT * FROM camerieri";
$result = mysqli_query($conn, $sql);
if($result){

  if(mysqli_num_rows($result)>0){
      while ($row = mysqli_fetch_assoc($result)){
          echo "id: ".$row["id_cameriere"]. " ". "Name: ".$row["nome"]." ".$row["cognome"] . "<br>";
      }
  }else{
      echo "non c'è nessun cameriere";
  }


}else{
    echo "ERRORE" . mysqli_error($conn);
}
mysqli_close($conn);
