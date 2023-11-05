<!DOCTYPE html>
<html>
    <head>
        <h1>Practice 4</h1>
    </head>
    <body>
        <form method="post">
            <label for="number">Enter number:</label>
            <input type="text" name="number" id="number" required>
            <input type="submit" value="Display Multiplication Table">
        </form>
        <?php
            if ($_SERVER["REQUEST_METHOD"] == "POST") {
                $number = intval($_POST["number"]);
        
                echo "<h2>Multiplication Table for $number</h2>";
                echo "<table border='1'>";
                for ($i = 0; $i <= $number; $i++) {
                    echo "<tr>";
                    for ($j = 0; $j <= $number; $j++) {
                        if ($i == 0 and $j != 0) {
                            echo "<td>$j</td><br>";
                        }

                        if ($j == 0) {
                            echo "<td>$i</td>";
                        }
                        else {
                            if ($i != 0) {
                                $result = $i * $j;
                                echo "<td>$i x $j = $result</td>";
                            }
                        }
                    }
                    echo "</tr>";
                }
                echo "</table>";
            }
        ?>
    </body>
</html>