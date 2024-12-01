import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)

    var t = scanner.nextInt()

    while (t-- > 0) {
        val n = scanner.nextInt()
        val da = scanner.nextInt()
        val va = scanner.nextInt()
        val dc = scanner.nextInt()
        val vc = scanner.nextInt()
        val d = scanner.nextInt()

        var v = vc - (dc - d)
        if (v < va) {
            v = va
        }

        println(v)
    }
}
