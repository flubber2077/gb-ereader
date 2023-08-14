## current thoughts

printf does basically everything i want.

## Helpful info

- Going to use mostly this alphabet encoding https://en.wikipedia.org/wiki/Windows-1252
- Control characters (except horizontal tab, line feed, and carriage return) have nothing to do inside an HTML document.
  - This gives me a couple extra controls or characters to work with

## Steps

Should go from hardest to easiest.

- GB displays text in a usable way. Can just go forward for now on A and then wait.
- HTML -> GB (basic)
- Chapter links.
- epub to HTML
  -ftfy library will be helpful
- HTML -> GB (edge cases)

## Bare Minimum Needed

Predictions, Steps:

### Easy

- epub -> html
- ascii character set

### Medium

- Define custom GB format
- Display characters

### Difficult

- html -> custom GB format. Lots of edge cases
- Chapter links
- Book links

## Nice to haves

- I'm actually going to need memory to keep readers place between power. dangit.
- Variable width font!
- Multi-language support. Use windows 1252, can add more later.
- Border
- Sound
- Splash screen
- Images?
  - Size isn't really the issue, it's going to be bit depth. 4 bits to work with. Could also limit it to GBC to wring out slightly more SN.
  - Would need to adjust contrast and dithering to image to combat bit depth.
  - Zoom seems out of scope as it would need to be content aware.
