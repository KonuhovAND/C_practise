import numpy as np
from PIL import Image
import os
from pprint import pprint
import time

def save_image(array, filename):
    """Сохраняет numpy-массив (0 и 1) как ч/б изображение."""
    # Переводим 1 -> 255 (белый), 0 -> 0 (чёрный)
    img = Image.fromarray((array * 255).astype(np.uint8), mode='L')
    img.save(filename)

def horizontal_lines(size=32, line_thickness=2):
    """
    32 картинки с горизонтальной линией на разной высоте.
    Высота линии меняется от 0 до size-1.
    """
    os.makedirs("horizontal", exist_ok=True)
    images = []

    for y_offset in range(size):
        arr = np.zeros((size, size), dtype=np.uint8)
        # Рисуем линию толщиной line_thickness
        half_t = line_thickness // 2
        y_start = max(0, y_offset - half_t)
        y_end = min(size, y_offset + line_thickness - half_t)
        arr[y_start:y_end, :] = 1

        images.append(arr)
        save_image(arr, f"horizontal/line_y_{y_offset:02d}.png")

    print(f"Создано {len(images)} изображений с горизонтальными линиями в папке 'horizontal/'")
    return images

def vertical_lines(size=32, line_thickness=2):
    """
    32 картинки с вертикальной линией на разной позиции по X.
    """
    os.makedirs("vertical", exist_ok=True)
    images = []

    for x_offset in range(size):
        arr = np.zeros((size, size), dtype=np.uint8)
        half_t = line_thickness // 2
        x_start = max(0, x_offset - half_t)
        x_end = min(size, x_offset + line_thickness - half_t)
        arr[:, x_start:x_end] = 1

        images.append(arr)
        save_image(arr, f"vertical/line_x_{x_offset:02d}.png")

    print(f"Создано {len(images)} изображений с вертикальными линиями в папке 'vertical/'")
    return images

def circles_different_diameter(size=32):
    """
    32 картинки с окружностями разного диаметра.
    Центр окружности всегда в середине изображения (size/2, size/2).
    Диаметр меняется от 1 до size (или чуть больше размера).
    Рисуется только контур окружности (граница).
    """
    os.makedirs("circles", exist_ok=True)
    images = []

    cx, cy = (size - 1) / 2, (size - 1) / 2  # центр

    for diameter in range(1, size + 1):
        arr = np.zeros((size, size), dtype=np.uint8)
        radius = diameter / 2.0

        # Создаём сетку координат
        Y, X = np.ogrid[:size, :size]
        dist = np.sqrt((X - cx)**2 + (Y - cy)**2)

        # Рисуем окружность: точки, где расстояние близко к радиусу (контур)
        thickness = 1.0
        # Всё, что между radius-thickness и radius+thickness — контур
        ring_mask = (dist >= radius - thickness/2) & (dist <= radius + thickness/2)
        arr[ring_mask] = 1

        images.append(arr)
        save_image(arr, f"circles/circle_d_{diameter:02d}.png")

    print(f"Создано {len(images)} изображений с окружностями в папке 'circles/'")
    return images


def build_matrix(folder_paths=["./horizontal", "./vertical", "./circles"],target_size =(32,32),expected_count = 96):
    files = []
    for folder in folder_paths:
        files.extend([os.path.join(folder, f) for f in os.listdir(folder) if f.endswith('.png')])
    if len(files) != expected_count:
        raise ValueError(f"Ожидалось {expected_count} файлов, но найдено {len(files)}. Проверьте папки и их содержимое.")
    files.sort()
    
    matrix = np.zeros((expected_count, target_size[0] * target_size[1]), dtype=np.float32)

    for i,f in enumerate(files):
        img = Image.open(f)
        img = img.resize(target_size, Image.Resampling.NEAREST)  # Убедимся, что размер правильный
        matrix[i] = np.array(img).flatten() //255 # Разворачиваем в строку и сохраняем в матрицу
    
    return matrix

def generate_independent_angled_lines(target_rang = 256,size = 32,thickness = 1):
    os.makedirs("angled_lines", exist_ok=True)
    independent_images,independent_vectors= [],[]
    angles = list(range(0,180,15)) 
    offsets = list(range(-size//2, size//2 + 1))
    cx, cy = size / 2.0, size / 2.0
    Y, X = np.ogrid[:size, :size]
    X_c = X - cx
    Y_c = Y - cy

    for angle in angles:
        for offset in offsets:
            if len(independent_images) >= target_rang:
                break
            arr = np.zeros((size, size), dtype=np.uint8)
            theta = np.radians(angle)
            
            dist = np.abs(X_c * np.cos(theta) + Y_c * np.sin(theta) - offset)
            arr[dist <= thickness/2] = 1

            new_vec = arr.flatten()

            is_independent = False
            if len(independent_images) == 0:
                is_independent = True  
            else:
                temp_matrix = np.vstack([np.array(independent_vectors), new_vec])
                if np.linalg.matrix_rank(temp_matrix) > len(independent_images):
                    is_independent = True

            if is_independent:
                independent_images.append(arr)
                independent_vectors.append(new_vec)
                save_image(arr, f"angled_lines/line_{len(independent_images)-1:03d}.png")
                # print(f"Добавлена: угол {angle}°, сдвиг {offset}")

    final_matrix = np.array(independent_vectors)
    print(f"\nГотово! Создано {len(independent_images)} линейно независимых изображений.")
    return final_matrix

    


    
# =======================
# ГЕНЕРАЦИЯ ВСЕХ НАБОРОВ
# =======================
if __name__ == "__main__":
    SIZE = 32
    start = time.time()
    # 1. Горизонтальные линии (32 штуки)
    h_images = horizontal_lines(SIZE, line_thickness=2)

    # 2. Вертикальные линии (32 штуки)
    v_images = vertical_lines(SIZE, line_thickness=2)

    # 3. Окружности разного диаметра (32 штуки)
    c_images = circles_different_diameter(SIZE)

    print("\nГотово! Всего создано:")
    print(f"  - горизонтальные линии: {len(h_images)} шт.")
    print(f"  - вертикальные линии:   {len(v_images)} шт.")
    print(f"  - окружности:           {len(c_images)} шт.")
    
    
    M= build_matrix()
    pprint({print(M[i]) for i in range(M.shape[0])})
    print(len(set(tuple(row) for row in M)), "уникальных строк в матрице M")
    
    print(f"Матрица M размером {M.shape} успешно создана.{np.linalg.matrix_rank(M)}")
    print(f"\nРавен ли ранг 96? - {"YES" if np.linalg.matrix_rank(M) == 96 else "NO"} ")

    M_new = generate_independent_angled_lines()
    
    print(f"Матрица M_new размером {M_new.shape} успешно создана. Ранг: {np.linalg.matrix_rank(M_new)}")

    print(f"{time.time() - start} заняло секунд")