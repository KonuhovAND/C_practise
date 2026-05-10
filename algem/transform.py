from PIL import Image
import numpy as np

def linear_transform(
    input_path: str,
    output_path: str,
    matrix: list[list[float]],  
    origin: tuple[int, int] = (0, 0),  
    background_color: tuple[int, int, int] = (255, 255, 255)  
):
    # Открываем изображение и переводим в RGB
    img = Image.open(input_path).convert("RGB")
    W, H = img.size
    pixels_in = np.array(img)  

    out_img = Image.new("RGB", (W, H), background_color)
    pixels_out = np.array(out_img)

    # Вычисляем обратную матрицу для обратного отображения (reverse mapping).
    # Это нужно, чтобы на итоговом изображении не было пустых пикселей (дырок)
    # из-за погрешностей округления при трансформации.
    M_inv = np.linalg.inv(matrix)
    a, b = M_inv[0]
    c, d = M_inv[1]
    ox, oy = origin

    # --- ОБРАТНЫЙ ПРОХОД ---
    # Для каждого пикселя выходного холста вычисляем, откуда он "пришел"
    # из исходного изображения под действием обратной матрицы.
    for y_out in range(H):
        for x_out in range(W):
            x_in = int(a * (x_out - ox) + b * (y_out - oy) + ox)
            y_in = int(c * (x_out - ox) + d * (y_out - oy) + oy)

            # Если точка "откуда пришли" лежит внутри исходника, забираем ее цвет
            if 0 <= x_in < W and 0 <= y_in < H:
                pixels_out[y_out, x_out] = pixels_in[y_in, x_in]

    Image.fromarray(pixels_out).save(output_path)
    print(f"Сохранено: {output_path}")


if __name__ == "__main__":
    photo = "cat.jpg"

    # Начало координат (выбрано на фото)
    photo = "cat.jpg"
    
    # Ставим точку в центр фото (для 474x356 это ~237, 178)
    pivot = (237, 178)
    
    # Векторы "плитки" (теперь они соразмерны объекту на фото)
    # Представь, что это стороны прямоугольника, в который вписана голова кота
    v1 = np.array([100, 20])   # Вектор вдоль воображаемой плитки
    v2 = np.array([-20, 80])   # Вектор перпендикулярный v1
    
    # Формируем матрицу перехода V
    V = np.array([v1, v2]).T
    
    # Матрица поворота R на 90 градусов (стандартная в линейной алгебре)
    #
    R = np.array([[0, -1], 
                  [1,  0]])
    
    # Матрица трансформации A^-1 * R * A
    M = V @ R @ np.linalg.inv(V)
    mat = M.tolist()
    
    print(f"Применяем матрицу: {mat}")
    linear_transform(photo, "tiled_rotated.jpg", mat, origin=pivot)