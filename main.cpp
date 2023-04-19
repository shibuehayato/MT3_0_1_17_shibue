#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LE2B_17_シブエハヤト_タイトル";

struct Vector3
{
	float x, y, z;
};

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

// 加算
Vector3 Add(Vector3 v1, Vector3 v2);
// 減算
Vector3 Subtract(Vector3 v1, Vector3 v2);
// スカラー倍
Vector3 Multiply(float scalar, const Vector3 v1);
// 内積
float Dot(const Vector3 v1, const Vector3 v2);
// 長さ (ノルム)
float Length(const Vector3 v1);
// 正規化
Vector3 Normalize(const Vector3 v2);

void VectorScreenPrintf(int x, int y, Vector3 vector, const char* label);

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 v1{ 1.0f, 3.0f, -5.0f };
	Vector3 v2{ 4.0f, -1.0f, 2.0f };
	float k = { 4.0f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Vector3 resultAdd = Add(v1, v2);
		Vector3 resultSubtract = Subtract(v1, v2);
		Vector3 resultMultiply = Multiply(k, v1);
		float resultDot = Dot(v1, v2);
		float resultLength = Length(v1);
		Vector3 resultNormalize = Normalize(v2);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		VectorScreenPrintf(0, 0, resultAdd, "  : Add");
		VectorScreenPrintf(0, kRowHeight, resultSubtract, "  : Subtract");
		VectorScreenPrintf(0, kRowHeight * 2, resultMultiply, "  : Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f  : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f  : Length", resultLength);
		VectorScreenPrintf(0, kRowHeight * 5, resultNormalize, "  : Normalize");
		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

void VectorScreenPrintf(int x, int y, Vector3 vector, const char* label)
{
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

Vector3 Add(Vector3 v1, Vector3 v2)
{
	Vector3 num;

	float a[3] = { v1.x, v1.y, v1.z };
	float b[3] = { v2.x, v2.y, v2.z };

	num.x = a[0] + b[0];
	num.y = a[1] + b[1];
	num.z = a[2] + b[2];

	return num;
}

Vector3 Subtract(Vector3 v1, Vector3 v2)
{
	Vector3 num;

	float a[3] = { v1.x, v1.y, v1.z };
	float b[3] = { v2.x, v2.y, v2.z };

	num.x = a[0] - b[0];
	num.y = a[1] - b[1];
	num.z = a[2] - b[2];

	return num;
}

Vector3 Multiply(float scalar, const Vector3 v1)
{
	Vector3 num;

	num.x = scalar * v1.x;
	num.y = scalar * v1.y;
	num.z = scalar * v1.z;

	return num;
}

float Dot(const Vector3 v1, const Vector3 v2)
{
	float num;

	num = v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;

	return num;
}

float Length(const Vector3 v1)
{
	float num;

	num = sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);

	return num;
}

Vector3 Normalize(const Vector3 v2)
{
	Vector3 num;
	float length = sqrtf(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z);

	float newX = v2.x;
	float newY = v2.y;
	float newZ = v2.z;

	if (length != 0.0f) {
		newX = v2.x / length;
		newY = v2.y / length;
		newZ = v2.z / length;

	}

	num.x = newX;
	num.y = newY;
	num.z = newZ;

	return num;
}