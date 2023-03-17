#include<bits/stdc++.h>

using namespace std;
int angle1, angle2, angle3;

/*
 * equilateralCheck() checks that the triangle is Equilateral.
 * If the triangle is Equilateral, all angles are 60
 */

bool equilateralCheck() {
    if (angle1 != 60) return false;  // one of the angle is not 60
    if (angle2 != 60) return false;  // one of the angle is not 60
    if (angle3 != 60) return false;  // one of the angle is not 60
    return true;                    // all of the angles are 60
}

/*
 * isoscelesCheck() checks that the triangle is isosceles.
 * If the two angles are equal, the triangle is isosceles.
 * Else the triangle is not isosceles.
 */

bool isoscelesCheck() {
    if (angle1 == angle2) return true;  // two angles are equal
    if (angle1 == angle3) return true;  // two angles are equal
    if (angle3 == angle2) return true;  // two angles are equal
    return false; // No two angles of equal angle exist.
}

/*
 * scaleneCheck() check that the triangle is scalene.
 * If the triangle is scalene, there is no equal angle.
 */

bool scaleneCheck() {
    // all of angles are different
    if (angle1 != angle2 and angle2 != angle3 and angle3 != angle1)
        return true;
    
    return false; // at least one pair of angles are equal
}

string solve() {
    int sum = angle1 + angle2 + angle3;
    if (sum != 180) {
        return "Error";
    }
    if (equilateralCheck()) {
        return "Equilateral";
    }
    if (isoscelesCheck()) {
        return "Isosceles";
    }
    if (scaleneCheck()) {
        return "Scalene";
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
  
    cin >> angle1;
    cin >> angle2;
    cin >> angle3;
    
    auto rst = solve();
    cout << rst << "\n";
    return 0;
}
