import { Canvas, loadImage } from "canvas";
import { writeFile } from "fs/promises";

async function readImage(inputPath, width, height) {
  const content = await loadImage(inputPath);
  const canvas = new Canvas(width, height, "image");
  const ctx = canvas.getContext("2d");
  ctx.drawImage(content, 0, 0);
  const stream = canvas.toBuffer();

  let counter = 0;
  let result = [];
  for (let x = 0; x < width; x++) {
    let r = [];
    for (let y = 0; y < height; y++) {
      r.push([...ctx.getImageData(x, y, 1, 1).data][0] === 255 ? 0 : 1);
    }
    result.push(
      Number(
        "0x" +
          Number("0b" + r.join(""))
            .toString(16)
            .padStart(2, "0")
            .toUpperCase()
      )
    );
    counter++;
    if (counter === 4) {
      counter = 0;
      result.push(0xff);
    }
  }

  const buf = Buffer.from(result);

  await writeFile(inputPath + ".bin", buf);
}

readImage("font-abc-both.png",208, 8);
// readImage("font-abc-uppercase.png", 104, 8);
