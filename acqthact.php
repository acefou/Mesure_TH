 <?php
 
	//baselocale
	//$servername = "localhost";
	//$username = "root";
	//$password = "";
	//$dbname = "acefoubacefou";
	//base acefou mysqli("localhost","root","","acefoubacefou");


// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT format(`mes_th`,1) as th ,format(`mes_hu`,1) as hu,`date_mesure` as date 
FROM tab_esp_mesure ORDER BY `date_mesure` DESC LIMIT 1; ";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        //echo "th: " . $row["th"]. " - hu: " . $row["hu"]. " " . $row["date"]. <br>";
		echo $row["th"].'°';
    }
} else {
    echo "0 results";
}
$conn->close();
?> 