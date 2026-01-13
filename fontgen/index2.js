import { Canvas, loadImage } from "canvas";
import { writeFile } from "fs/promises";

async function readImage(inputPath, width, height) {
  const content = await loadImage(inputPath);
  const canvas = new Canvas(width, height, "image");
  const ctx = canvas.getContext("2d");
  ctx.drawImage(content, 0, 0);

  let result = [];
  for (let x = 0; x < width; x++) {
    let r = [];
    for (let y = 0; y < height; y++) {
      const color = [...ctx.getImageData(x, y, 1, 1).data];
      if (y === 0 && color[0] === 0 && color[1] === 255) {
        result.push(0xff);
        break;
      }
      r.push([...ctx.getImageData(x, y, 1, 1).data][0] === 255 ? 0 : 1);
    }
    if (r.length)
      result.push(
        Number(
          "0x" +
            Number("0b" + r.join(""))
              .toString(16)
              .padStart(2, "0")
              .toUpperCase()
        )
      );
  }

  const buf = Buffer.from(result);

  await writeFile(inputPath + ".bin", buf);
}

readImage("font2-abc-lowercase.png", 122, 8);
// readImage("font-abc-uppercase.png", 104, 8);
