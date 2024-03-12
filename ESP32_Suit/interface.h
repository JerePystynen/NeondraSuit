const char HTML_CONTENT[] PROGMEM = R"KEWL(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Neondra Control Panel</title>
    <link rel="shortcut icon" href="https://neondra.com/neondra/assets/images/logo/favicon.png" type="image/x-icon">
    <style>
        * {
            margin: 0;
            padding: 0;
            z-index: 1;
            font-family: Poppins, sans-serif;
        }

        html {
            width: 100vw;
            overflow: hidden;
        }

        body {
            height: 100vh;
            background: #302535;
            background-size: cover;
            color: #ECFBFF;
            font-size: 14px;
        }

        .svg-element {
            position: absolute;
            width: 100%;
        }

        section {
            position: absolute;
            width: auto;
            min-width: 300px;
            left: 50%;
            transform: translateX(-50%);
            top: 5%;
            display: flex;
            flex-direction: column;
            justify-content: right;
            align-items: baseline;
        }

        section:nth-of-type(1) {
            width: auto;
        }

        section.center-control-panel {
            pointer-events: none;
            -webkit-user-select: none;
            -moz-user-select: none;
            user-select: none;
            width: 75%;
            left: 50%;
            top: 50%;
            transform: translateX(-50%) translateY(-50%);
            display: flex;
            flex-direction: row;
            align-items: center;
            justify-content: space-around;
        }

        section.center-control-panel .left,
        section.center-control-panel .right {
            width: 320px;
            pointer-events: all;
            -webkit-user-select: all;
            -moz-user-select: all;
            user-select: all;
        }

        section.suit-mode-selection {
            position: absolute;
            bottom: 0;
            width: 30%;
            left: 50%;
            transform: translateX(-50%);
        }

        section.audioplayer {
            width: auto;
            right: 0;
            top: 50%;
            transform: translateY(-50%);
        }

        .flex {
            display: flex;
            flex-direction: column;
            justify-content: center;
        }

        .flex-wrap {
            display: flex;
            flex-wrap: wrap;
            align-items: flex-start;
        }

        .flex-align {
            display: flex;
            align-items: center;
            justify-content: space-between;
        }

        body,
        div {
            position: relative;
        }

        body,
        nav,
        footer,
        h1,
        h2,
        h3 {
            width: 100%;
        }

        h1,
        h2,
        h3 {
            margin: 16px 0;
        }

        input {
            cursor: pointer;
        }

        a {
            margin: 6px 0;
            text-decoration: none;
        }

        a,
        a:visited {
            color: #af45cc;
        }

        img {
            width: 32px;
        }

        .bottom-svg-element {
            position: absolute;
            bottom: 0;
            width: 100vw;
        }

        .status-info-container {
            display: ruby;
            margin: 12px;
        }

        .status-info-container .item {
            cursor: default;
            width: 100px;
            height: 100px;
            display: flex;
            align-items: center;
            justify-content: center;
            flex-direction: column;
            font-size: 14px;
            margin: 2px;
        }

        .status-info-container .item .circle {
            position: absolute;
            border-radius: 50%;
        }

        .status-info-container .item .circle.a {
            width: 74%;
            height: 74%;
            opacity: 0.8;
            border: solid #fff 1px;
            filter: blur(4px);
        }

        .status-info-container .item .circle.b {
            width: 90%;
            height: 90%;
            border: solid #fff 1px;
        }

        .status-info-container .item .circle.c {
            opacity: 0.7;
            width: 94%;
            height: 94%;
            border: solid #fff 1px;
        }

        .status-info-container .item .circle.d {
            opacity: 0.6;
            width: 100%;
            height: 100%;
            border: dotted #fff 2px;
            animation: rotatingCircleAnim 2s infinite linear;
        }

        .status-info-container .item .circle.e {
            width: 112%;
            height: 112%;
            opacity: 0.4;
            border: solid #fff 1px;
            filter: blur(4px);
        }

        .status-info-container .item span {
            margin: 1px;
        }

        .status-info-container .item .status {
            font-size: 28px;
        }

        @keyframes rotatingCircleAnim {
            0% {
                transform: rotateZ(0deg);
            }

            100% {
                transform: rotateZ(-360deg);
            }
        }

        .status-connections-container {
            display: ruby;
            margin: 8px 14px 12px 14px;
        }

        .status-connections-container .item {
            cursor: default;
            width: 76px;
            height: 76px;
            display: flex;
            align-items: center;
            justify-content: center;
            flex-direction: column;
            font-size: 14px;
            margin: 3px;
        }

        .status-connections-container .item[connected=true] .circle.b {
            border: solid lime 1px;
        }

        .status-connections-container .item .circle {
            position: absolute;
            border-radius: 50%;
            border: solid #fff 1px;
        }

        .status-connections-container .item .circle.a {
            width: 74%;
            height: 74%;
            opacity: 0.8;
            border: solid #fff 1px;
            filter: blur(4px);
        }

        .status-connections-container .item .circle.b {
            opacity: 0.8;
            width: 90%;
            height: 90%;
            border: solid red 1px;
        }

        .status-connections-container .item .circle.d {
            opacity: 0.6;
            width: 100%;
            height: 100%;
            border: dotted #fff 2px;
            animation: rotatingCircleAnim 2s infinite linear;
        }

        .button {
            width: -moz-fit-content;
            width: fit-content;
            cursor: pointer;
            background-color: #333333;
            padding: 18px;
            border-radius: 12px;
            margin: 6px;
        }

        .button:first-of-type {
            margin-left: 0px;
            margin-right: 0px;
        }

        .button[selected=true] {
            color: #ECFBFF;
        }

        .button[selected=true],
        .button[selected=true].icon,
        .button[selected=true].small-icon {
            background-color: #af45cc;
        }

        .button[selected=true] img,
        .button[selected=true]:hover img {
            filter: brightness(0.78) sepia(100%) saturate(500%) hue-rotate(45deg);
        }

        .button.icon {
            background-color: #222222;
            padding: 2px;
            cursor: pointer;
        }

        .button.icon img {
            width: 100px;
        }

        .button.small-icon {
            background-color: #222222;
            padding: 12px;
            cursor: pointer;
        }

        .button.small-icon:hover img {
            filter: brightness(0.78) sepia(100%) saturate(300%) hue-rotate(45deg);
        }

        .button img {
            width: 4spx;
        }

        .button-fullscreen {
            position: absolute;
            cursor: pointer;
            width: 32px;
            height: 32px;
            background-color: #261d46;
            border-radius: 12px;
            padding: 10px;
            right: 0;
            bottom: 15px;
            transition: transform 0.2s ease-out;
        }

        .button-fullscreen:hover {
            transform: scale(104%);
        }

        .button-fullscreen img {
            width: 32px;
        }

        .audio-player {
            width: 270px;
            background-color: #261d46;
            border-radius: 8px;
            padding: 12px;
        }

        .audiofiles-vertical,
        .audiofiles-horizontal {
            width: 100%;
            display: flex;
            margin: 6px 0;
        }

        .audiofiles-vertical[files-found=false],
        .audiofiles-horizontal[files-found=false] {
            height: 200px;
            align-items: center;
            justify-content: center;
        }

        .audiofiles-vertical[files-found=false] .item,
        .audiofiles-horizontal[files-found=false] .item {
            display: none;
        }

        .audiofiles-vertical[files-found=true],
        .audiofiles-horizontal[files-found=true] {
            height: auto;
            max-height: 312px;
        }

        .audiofiles-vertical[files-found=true] .status-no-files,
        .audiofiles-horizontal[files-found=true] .status-no-files {
            display: none;
        }

        .audiofiles-vertical .item,
        .audiofiles-horizontal .item {
            width: 85%;
        }

        .audiofiles-vertical {
            flex-direction: column;
        }

        .audiofiles-vertical[files-found=true] {
            overflow-y: scroll;
        }

        .audiofiles-vertical[files-found=false] {
            overflow-y: hidden;
        }

        .audiofiles-vertical .item {
            margin: 2px 0;
        }

        .audiofiles-horizontal {
            flex-direction: row;
        }

        .audiofiles-horizontal>a {
            flex: 50%;
        }

        .audiofiles-horizontal[files-found=true] {
            overflow-x: scroll;
        }

        .audiofiles-horizontal[files-found=false] {
            overflow-x: hidden;
        }

        .audiofiles-horizontal .item {
            margin: 0 2px;
        }

        canvas {
            position: absolute;
            z-index: 0;
        }

        footer {
            position: absolute;
            width: 99%;
            bottom: 10px;
            text-align: right;
        }

        footer span {
            font-style: italic;
            color: lightgray;
        }

        @media screen and (max-width: 915px) {

            section.split-left,
            section.split-right {
                width: 100%;
            }
        }

        /* DEFAUlT CODE, REMOVE IN PRODUCTION ! */
        body {
            background-color: #131b2e;
            display: flex;
            flex-wrap: wrap;
            align-items: flex-start;
            min-height: 100vh;
        }

        .controls-container {
            margin-top: auto;
            margin-bottom: auto;
            margin-left: 10px;
        }

        .controls-container .sliders,
        .controls-container .radios {
            display: flex;
        }

        .sexy-slider {
            position: relative;
            margin: auto;
            width: 100px;
            height: 480px;
            display: flex;
            justify-content: center;
            background-color: #183253;
            border-radius: 38px 38px 28px 28px;
            overflow: hidden;
            border: 2px solid #8296da;
            box-shadow: 0 0 0.5em #8296da, 2px 2px 8px #1e1e27;
            outline: 2px #505069 solid;
            transition: outline 0.12s ease-out;
        }

        .sexy-slider:hover {
            outline: 2px #abb0d3 solid;
        }

        .sexy-slider:hover>.sliding-element {
            background-color: #8296da;
        }

        .sexy-slider .sliding-element {
            position: absolute;
            width: 100%;
            height: 100%;
            min-height: 12%;
            bottom: 0;
            background-color: #405c89;
            box-shadow: inset 0 0 0.25em #8296da;
            border-radius: 28px 28px 20px 20px;
            -webkit-user-select: none;
            -moz-user-select: none;
            user-select: none;
            pointer-events: none;
            transition: background-color 0.1s ease-out;
        }

        .sexy-slider .sliding-element::after {
            content: "";
            position: absolute;
            top: 16px;
            height: 4px;
            width: 60%;
            border-radius: 2px;
            background-color: rgba(255, 204, 255, 0.8);
            left: 50%;
            transform: translateX(-50%);
            box-shadow: 1px 2px 4px #35393a;
        }

        .sexy-slider input {
            position: absolute;
            width: 480px;
            height: 100px;
            top: 50%;
            transform: translateY(-50%) rotateZ(-90deg);
            opacity: 0;
        }

        .sexy-slider span {
            color: #fff;
            margin-bottom: 8px;
            align-self: end;
            font-family: Poppins, sans-serif;
            z-index: 1;
            font-size: 120%;
            -webkit-user-select: none;
            -moz-user-select: none;
            user-select: none;
            pointer-events: none;
        }

        .sexy-slider h4 {
            position: absolute;
            z-index: 1;
            top: 56%;
            left: 50%;
            transform: translateX(-50%) rotateZ(90deg);
            white-space: nowrap;
            -webkit-user-select: none;
            -moz-user-select: none;
            user-select: none;
            pointer-events: none;
        }

        .sexy-radio,
        .sexy-radio-6 {
            position: relative;
            margin: 12px 6px;
            width: 230px;
            height: 80px;
            background-color: #183253;
            border-radius: 42px;
            overflow: hidden;
            border: 2px solid #6778b3;
            box-shadow: 0 0 0.5em #8296da, 2px 2px 8px #1e1e27;
            outline: 1px #505069 solid;
            transition: outline 0.12s ease-out;
        }

        .sexy-radio:hover,
        .sexy-radio-6:hover {
            outline: 2px #abb0d3 solid;
        }

        .sexy-radio:hover::before,
        .sexy-radio-6:hover::before {
            background-color: #8296da;
        }

        .sexy-radio input,
        .sexy-radio-6 input {
            width: 33.33%;
            opacity: 0;
        }

        .sexy-radio div,
        .sexy-radio-6 div {
            position: absolute;
            width: 100%;
            height: 100%;
            display: flex;
            justify-content: center;
            align-content: center;
        }

        .sexy-radio span,
        .sexy-radio-6 span {
            width: 33.33%;
            font-family: Poppins, sans-serif;
            color: white;
            text-align: center;
            align-self: center;
        }

        .sexy-radio[value="1"]::before,
        .sexy-radio-6[value="1"]::before {
            transform: translateX(0%);
        }

        .sexy-radio[value="2"]::before,
        .sexy-radio-6[value="2"]::before {
            transform: translateX(100%);
        }

        .sexy-radio[value="3"]::before,
        .sexy-radio-6[value="3"]::before {
            transform: translateX(200%);
        }

        .sexy-radio::before,
        .sexy-radio-6::before {
            content: "";
            position: absolute;
            width: 33.33%;
            background-color: #405c89;
            box-shadow: inset 0 0 0.25em #6577b0;
            height: 100%;
            border-radius: 42px;
            -webkit-user-select: none;
            -moz-user-select: none;
            user-select: none;
            pointer-events: none;
            transition: transform 0.4s ease-in-out, background-color 0.1s ease-out;
        }

        .sexy-radio.wide,
        .sexy-radio-6.wide {
            width: 500px;
        }

        .sexy-radio.wide[value="4"]::before,
        .sexy-radio-6.wide[value="4"]::before {
            transform: translateX(300%);
        }

        .sexy-radio.wide[value="5"]::before,
        .sexy-radio-6.wide[value="5"]::before {
            transform: translateX(400%);
        }

        .sexy-radio.wide[value="6"]::before,
        .sexy-radio-6.wide[value="6"]::before {
            transform: translateX(500%);
        }

        .sexy-radio.wide input,
        .sexy-radio.wide::before,
        .sexy-radio-6.wide input,
        .sexy-radio-6.wide::before {
            width: 16.66%;
        }

        .sexy-music-player {
            margin-left: auto;
            margin-top: auto;
            margin-bottom: auto;
            margin-right: 18px;
            right: 0;
        }

        @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300&display=swap');

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Poppins', sans-serif;
            color: #fff;
        }

        :root {
            --red-clr: #5f70a4;
            --orange-clr: #00b3ff;
            --black-clr: #1a0000;
        }

        .container {
            position: relative;
            overflow: hidden;
            border-radius: 1em;
            border: 2px solid var(--red-clr);
            box-shadow: 0 0 .5em var(--red-clr);
        }

        .audio-player {
            width: 350px;
            height: 70vh;
            background-color: var(--black-clr);
            display: grid;
            grid-template-rows: 5fr 1fr 1fr 1.2fr;
            border-radius: 1em;
            box-shadow: inset 0 0 .5em var(--red-clr);
            /* this boxshadow will give it a glowing neon effect */
            /* i'll use it quite often */
        }

        .img {
            position: relative;
            width: 100%;
            height: 100%;
        }

        .img::before {
            content: '';
            position: absolute;
            left: 50%;
            top: 50%;
            border-radius: 50%;
            width: 20%;
            aspect-ratio: 1/1;
            background-color: var(--black-clr);
            transform: translate(-50%, -50%);
            z-index: 2;
        }

        img {
            width: 100%;
            height: 100%;
            border-radius: 50%;
            object-fit: cover;
            transform: scale(.7);
            box-shadow: 0 0 1em var(--red-clr);
            animation: rotate 10000ms linear infinite;
            animation-play-state: paused;
        }

        @keyframes rotate {
            from {
                transform: rotate(0) scale(.7);
            }

            to {
                transform: rotate(360deg) scale(.7);
            }

            /* we'll rotate only when the audio is playing */
            /* so as default it'll be paused */
        }

        .audio-name {
            text-align: center;
            width: 80%;
            place-self: center;
        }

        .audio-name h1 {
            text-align: center;
            font-size: 1.1rem;
        }

        .audio-player nav {
            display: flex;
            align-items: center;
            justify-content: space-evenly;
        }

        nav button {
            font-size: 1.5rem;
            padding: .2em .7em;
            background-color: transparent;
            border: 2px solid #fff;
            border-radius: .3em;
            box-shadow: 0 0 .2em #fff,
                inset 0 0 .2em #fff;
            cursor: pointer;
            outline: none;
        }

        /* the reason it works is cause the script tag is already there
but we'll include it in the next part */
        nav button i {
            text-shadow: 0 0 .2em #fff;
        }

        nav button:active {
            transform: scale(.95);
        }

        .bar {
            display: flex;
            flex-direction: column;
            align-items: center;
            margin-top: 1.5rem;
        }

        .progress-bar {
            width: 80%;
            height: 5px;
            background-color: #fff;
            border-radius: 10px;
            position: relative;
            cursor: pointer;
            /* cause we'll add the feature to click where ever we want in the progress bar */
        }

        .progress {
            position: absolute;
            left: 0;
            top: 0;
            height: 100%;
            width: 100%;
            /* we'll change dinamically with JS. We'll leave it at 100% as default */
            background-color: var(--orange-clr);
            border-radius: 10px;
            transition: width 150ms ease-in-out;
        }

        .progress::before {
            content: '';
            position: absolute;
            top: 50%;
            right: 0;
            width: 15px;
            aspect-ratio: 1/1;
            background-color: var(--orange-clr);
            transform: translate(50%, -50%);
            border-radius: 50%;
            opacity: 0;
            transition: 200ms ease-in-out opacity;
        }

        .progress-bar:hover .progress::before {
            opacity: 1;
        }

        .time {
            display: flex;
            justify-content: space-between;
            width: 80%;
            margin-top: .5em;
        }


        .music-list {
            position: absolute;
            left: 0;
            bottom: 0;
            /* bruhhhhh. I knew something was wrong */
            width: 100%;
            height: 80%;
            background-color: var(--black-clr);
            box-shadow: inset 0 0 .5em var(--red-clr),
                0 0 .5em var(--red-clr),
                0 0 0 2px var(--red-clr);
            border-radius: 1em;
            z-index: 2;
            overflow-y: scroll;
            transition: 200ms ease-in-out transform;
            transform: translateY(101%);
        }

        .music-list nav {
            position: sticky;
            top: 0;
            left: 0;
            width: 100%;
            height: 10vh;
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 0 1rem;
            z-index: 5;
            background-color: var(--black-clr);
            box-shadow: inset 0 0 .5em var(--red-clr),
                0 0 .5em var(--red-clr),
                0 0 0 2px var(--red-clr);
        }

        .disabled {
            border: none;
            box-shadow: none;
            cursor: auto;
            padding: 0;
            display: flex;
            justify-content: space-between;
            align-items: center;
            flex-basis: 150px;
            user-select: none;
        }

        .disabled:active {
            transform: scale(1);
        }

        .disabled i {
            color: #b0b0b0;
            text-shadow: none;
        }

        .item-container {
            height: 90px;
            border-block: 1px solid var(--red-clr);
            box-shadow: 0 0 .5em var(--red-clr),
                inset 0 0 .5em var(--red-clr);
            padding: 0 .5em;
        }

        .item {
            cursor: pointer;
            display: flex;
            align-items: center;
            width: 100%;
            height: 100%;
        }

        .item:active {
            transform: scale(.97);
        }

        .coverImg {
            height: 70px;
            aspect-ratio: 1/1;
        }

        .coverImg img {
            box-shadow: 0 0 .5em var(--red-clr);
            user-select: none;
        }

        .info {
            margin-left: 1rem;
        }

        .info h3 {
            user-select: none;
            font-size: 1rem;
            font-weight: 300;
        }

        /* now we'll remove the scroll bar */
        .music-list::-webkit-scrollbar {
            display: none;
        }

        /* SHOW THE MUSIC LIST */
        .showMusicList {
            transform: translateY(0);
            /* since as default it'll be hidden */
        }

        /* since as default it is transform translated to 101% down */
    </style>
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.15.3/css/all.css">

    <script async src="https://unpkg.com/es-module-shims@1.6.3/dist/es-module-shims.js"></script>
    <script type="importmap">
    {
        "imports": {
            "three": "https://unpkg.com/three/build/three.module.js",
            "three/addons/": "https://unpkg.com/three/examples/jsm/"
        }
    }
    </script>
</head>

<body class="flex-wrap">

    <svg class="svg-element top-svg-element" width="1920" viewBox="0 0 1921 131" fill="none"
        xmlns="http://www.w3.org/2000/svg">
        <path d="M116.261 130.176H0V3.05176e-05H1921V130.176H1803.84L1674.5 41.0785H208.045L116.261 130.176Z"
            fill="#261d46" />
    </svg>
    <svg class="svg-element bottom-svg-element" width="1920" viewBox="0 0 1921 165" fill="none"
        xmlns="http://www.w3.org/2000/svg">
        <path
            d="M116.73 34.8241H0.5V165H1921V34.8241H1803.87L1705.61 92.8643H1244.69L1120.07 0H781.361L656.743 92.8643H177.442L116.73 34.8241Z"
            fill="#261d46" />
    </svg>

    <!-- <nav>
            <span>Welcome to Neondra's control panel v2.3, powered by an ESP8266!</span>
        </nav> -->

    <section>
        <div class="status-info-container">
            <div class="item">
                <span class="circle a"></span> <!-- Blurry halo -->
                <span class="circle b"></span> <!-- Dual-ring solid -->
                <span class="circle c"></span> <!-- Dual-ring solid -->
                <span class="circle d"></span> <!-- Dotted -->
                <span class="circle e"></span> <!-- Blurry halo -->
                <span class="circle f"></span> <!-- Solid by percentage 1-100 -->
                <span>Battery</span>
                <span class="status" id="status-battery-percentage">64 %</span>
                <span id="status-battery-remaining">2.3 h</span>
            </div>
            <div class="item">
                <span class="circle a"></span> <!-- Blurry halo -->
                <span class="circle b"></span> <!-- Dual-ring solid -->
                <span class="circle c"></span> <!-- Dual-ring solid -->
                <span class="circle d"></span> <!-- Dotted -->
                <span class="circle e"></span> <!-- Blurry halo -->
                <span class="circle f"></span> <!-- Solid by percentage 1-100 -->
                <span>Volts</span>
                <span class="status" id="status-battery-voltage">11.2</span>
                <span>V</span>
            </div>
            <div class="item">
                <span class="circle a"></span> <!-- Blurry halo -->
                <span class="circle b"></span> <!-- Dual-ring solid -->
                <span class="circle c"></span> <!-- Dual-ring solid -->
                <span class="circle d"></span> <!-- Dotted -->
                <span class="circle e"></span> <!-- Blurry halo -->
                <span class="circle f"></span> <!-- Solid by percentage 1-100 -->
                <span>Amps</span>
                <span class="status" id="status-battery-amperage">1249</span>
                <span>mAh</span>
            </div>
            <div class="item">
                <span class="circle a"></span> <!-- Blurry halo -->
                <span class="circle b"></span> <!-- Dual-ring solid -->
                <span class="circle c"></span> <!-- Dual-ring solid -->
                <span class="circle d"></span> <!-- Dotted -->
                <span class="circle e"></span> <!-- Blurry halo -->
                <span class="circle f"></span> <!-- Solid by percentage 1-100 -->
                <span>Volume</span>
                <span class="status" id="status-audiofile-volume">35 %</span>
                <span id="status-audiofile-volume-decibels">-2 dB</span>
            </div>
        </div>
        <div class="status-connections-container">
            <div class="item" title="Status: Connected" connected="true">
                <span class="circle a"></span> <!-- Blurry halo -->
                <span class="circle b"></span> <!-- Dual-ring solid -->
                <span class="circle c"></span> <!-- Dual-ring solid -->
                <span class="circle d"></span> <!-- Dotted -->
                <span class="circle e"></span> <!-- Blurry halo -->
                <span>Torso</span>
            </div>
            <div class="item" title="Status: Disconnected" connected="false">
                <span class="circle a"></span> <!-- Blurry halo -->
                <span class="circle b"></span> <!-- Dual-ring solid -->
                <span class="circle c"></span> <!-- Dual-ring solid -->
                <span class="circle d"></span> <!-- Dotted -->
                <span class="circle e"></span> <!-- Blurry halo -->
                <span>Wings</span>
            </div>
            <div class="item" title="Status: Connected" connected="true">
                <span class="circle a"></span> <!-- Blurry halo -->
                <span class="circle b"></span> <!-- Dual-ring solid -->
                <span class="circle c"></span> <!-- Dual-ring solid -->
                <span class="circle d"></span> <!-- Dotted -->
                <span class="circle e"></span> <!-- Blurry halo -->
                <span>Claws</span>
            </div>
            <div class="item" title="Status: Disconnected" connected="false">
                <span class="circle a"></span> <!-- Blurry halo -->
                <span class="circle b"></span> <!-- Dual-ring solid -->
                <span class="circle c"></span> <!-- Dual-ring solid -->
                <span class="circle d"></span> <!-- Dotted -->
                <span class="circle e"></span> <!-- Blurry halo -->
                <span>Legs</span>
            </div>
            <div class="item" title="Status: Disconnected" connected="false">
                <span class="circle a"></span> <!-- Blurry halo -->
                <span class="circle b"></span> <!-- Dual-ring solid -->
                <span class="circle c"></span> <!-- Dual-ring solid -->
                <span class="circle d"></span> <!-- Dotted -->
                <span class="circle e"></span> <!-- Blurry halo -->
                <span>Spitfire</span>
            </div>
        </div>
    </section>

    <div class="controls-container">
        <div class="sliders" style="display: flex;">
            <!-- 1x Whole Suit Brightness slider -->
            <div class="sexy-slider">
                <input type="range" name="" id="" min="0" max="100" value="50">
                <div class="sliding-element"></div>
                <span class="value">50%</span>
                <h4>Suit Brightness</h4>
            </div>
            <!-- 1x Volume slider -->
            <div class="sexy-slider">
                <input type="range" name="" id="" min="0" max="100" value="50">
                <div class="sliding-element"></div>
                <span class="value">50%</span>
                <h4>Suit Volume</h4>
            </div>
            <!-- 1x Empty slider -->
            <div class="sexy-slider">
                <input type="range" name="" id="" min="0" max="100" value="50">
                <div class="sliding-element"></div>
                <span class="value">50%</span>
                <h4>Empty Slider</h4>
            </div>
            <!-- 1x Wing Position slider -->
            <div class="sexy-slider">
                <input type="range" min="0" max="100" value="50" id="set-wings">
                <div class="sliding-element"></div>
                <span class="value">50%</span>
                <h4>Wing Position</h4>
            </div>
        </div>
        <div class="radios">
            <!-- Set Mic: Off, Modulated Playback, Normal Playback -->
            <div class="sexy-radio">
                <div>
                    <span>Off</span>
                    <span>Dragon</span>
                    <span>Normal</span>
                </div>
                <div>
                    <input type="radio" value="1">
                    <input type="radio" value="2">
                    <input type="radio" value="3">
                </div>
            </div>
            <!-- Set Fan speed: Off, Slow, Fast -->
            <div class="sexy-radio">
                <div>
                    <span>Off</span>
                    <span>Slow</span>
                    <span>Fast</span>
                </div>
                <div>
                    <input type="radio" value="1">
                    <input type="radio" value="2">
                    <input type="radio" value="3">
                </div>
            </div>

        </div>

    </div>

    <!-- Set color theme: Default, Rave, Happy, Cute, Angry, Swag -->
    <div class="sexy-radio wide" style="position: absolute; left: 50%; bottom: 2%; transform: translateX(-50%);">
        <div>
            <span>Default</span>
            <span>Rave</span>
            <span>Happy</span>
            <span>Cute</span>
            <span>Angry</span>
            <span>Swag</span>
        </div>
        <div>
            <input type="radio" value="1">
            <input type="radio" value="2">
            <input type="radio" value="3">
            <input type="radio" value="4">
            <input type="radio" value="5">
            <input type="radio" value="6">
        </div>
    </div>

    <div class="container sexy-music-player">
        <div class="audio-player">
            <div class="img">
                <img src="img/one.jpg" alt="">
            </div>
            <div class="audio-name">
                <h1>4am - KaizanBlue</h1>
            </div>
            <nav>
                <button class="backwardBtn">
                    <i class="fas fa-backward"></i>
                    <!-- its there but the color for all the elements is white -->
                </button>
                <button class="playBtn">
                    <i class="fas fa-play"></i>
                </button>
                <button class="forwardBtn">
                    <i class="fas fa-forward"></i>
                </button>
                <button class="musicListBtn">
                    <i class="fas fa-list"></i>
                </button>
            </nav>
            <div class="bar">
                <div class="progress-bar">
                    <div class="progress"></div>
                </div>
                <audio src="audio/4am - KaizanBlu.mp3"></audio>
                <div class="time">
                    <p class="audioCurrentTime">00:00</p>
                    <p class="fullLength">00:00</p>
                </div>
            </div>
        </div>
        <div class="music-list">
            <nav>
                <button class="disabled">
                    <i class="fas fa-list"></i>
                    Music List
                </button>
                <button class="xBtn">
                    <i class="fas fa-times"></i>
                </button>
            </nav>
            <div class="list">
                <div class="item-container">
                    <div class="item">
                        <div class="coverImg">
                            <img src="img/one.jpg" alt="">
                        </div>
                        <div class="info">
                            <h3>4am - KaizanBlue</h3>
                        </div>
                    </div>
                </div>
                <!-- like this  -->
            </div>
        </div>
    </div>

    <script>
        function toggleFullScreen() {
            var doc = window.document;
            var docEl = doc.documentElement;
            var requestFullScreen = docEl.requestFullscreen || docEl.mozRequestFullScreen || docEl.webkitRequestFullScreen || docEl.msRequestFullscreen;
            var cancelFullScreen = doc.exitFullscreen || doc.mozCancelFullScreen || doc.webkitExitFullscreen || doc.msExitFullscreen;
            if (!doc.fullscreenElement && !doc.mozFullScreenElement && !doc.webkitFullscreenElement && !doc.msFullscreenElement) {
                requestFullScreen.call(docEl);
            } else {
                cancelFullScreen.call(doc);
            }
        }

        // AJAX Requests
        function sendData(data) {
            fetch('/ajax', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/x-www-form-urlencoded'
                },
                body: 'plain=' + encodeURIComponent(data),
            }).then(response => response.text()).then(result => {
                console.log('Server response:', result);
            }).catch(error => {
                console.error('Error:', error);
            });
        }

        function playAudio(audioFile) {
            sendData(`play-audio=${audioFile}`);
        }

        const statusBatteryPercentageText = document.getElementById('status-battery-percentage');
        const statusBatteryAmperageText = document.getElementById('status-battery-amperage');
        const statusBatteryVoltageText = document.getElementById('status-battery-voltage');
        const statusAudiofileVolumeText = document.getElementById('status-audiofile-volume');
        function setStatusBatteryPercentage(value) {
            statusBatteryPercentageText.innerText = `${Math.round(value)} %`;
        }
        function setStatusBatteryAmperage(value) {
            statusBatteryAmperageText.innerText = `${Math.round(value)}`;
        }
        function setStatusBatteryVoltage(value) {
            statusBatteryVoltageText.innerText = `${Math.round(value * 10) / 10}`;
        }
        function setStatusAudiofileVolume(value) {
            statusAudiofileVolumeText.innerText = `${Math.round(value)} %`;
        }
        var statusLoopIndex = 0;
        function statusLoop() {
            setTimeout(() => {
                setStatusBatteryPercentage(62 + Math.random() * 6);
                setStatusBatteryAmperage(Math.random() * 1000);
                setStatusBatteryVoltage(9 + Math.random() * 3);
                setStatusAudiofileVolume(Math.random() * 100);
                if (statusLoopIndex < Infinity) statusLoop();
            }, 140);
        }
        statusLoop();

        /// SLIDERS
        // Set each Slider
        Array.from(document.getElementsByClassName('sexy-slider')).forEach(element => {
            element.getElementsByTagName('input')[0].oninput = function (event) {
                element.children[1].style.height = `${this.value}%`;
                element.children[2].innerText = `${this.value}%`;
            }
        });
        // Set each Radio
        Array.from(document.getElementsByClassName('sexy-radio')).forEach(element => {
            Array.from(element.getElementsByTagName('input')).forEach(radio => {
                radio.onclick = function (event) {
                    element.setAttribute('value', radio.value);
                }
            });
        });
        /// END SLIDERS
    </script>
    <!-- THREE.JS -->
    <script type="module">
        import * as THREE from 'three';
        import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';
        import { OrbitControls } from 'three/addons/controls/OrbitControls.js';

        const scene = new THREE.Scene();
        const camera = new THREE.PerspectiveCamera(60, window.innerWidth / window.innerHeight, 0.1, 1000);
        const renderer = new THREE.WebGLRenderer();
        const gltfLoader = new GLTFLoader();
        const raycaster = new THREE.Raycaster();

        renderer.setSize(window.innerWidth, window.innerHeight);
        document.body.appendChild(renderer.domElement);

        // Add ambient light
        const ambientLight = new THREE.AmbientLight(0xffffff, 3);
        scene.add(ambientLight);

        // Set the background image
        const textureLoader = new THREE.TextureLoader();
        const backgroundImage = textureLoader.load('/img/background.jpg');
        scene.background = backgroundImage;
        scene.backgroundIntensity = 0.15;

        const groundGeometry = new THREE.PlaneGeometry(5, 4);
        groundGeometry.rotateX(-1.57079633); // 90deg
        const backgroundMaterial = new THREE.MeshStandardMaterial({
            // map: backgroundImage,
            color: 0xFFFFFF,
            roughness: 0.8,
            metalness: 0.2,
        });
        const groundMesh = new THREE.Mesh(groundGeometry, backgroundMaterial);
        groundMesh.position.y = -5;
        scene.add(groundMesh);

        var leftWing = null, rightwing = null, targetWingRotation = 0;

        // Add mouse controls
        const controls = new OrbitControls(camera, renderer.domElement);
        controls.enablePan = false;
        controls.enableRotate = true;
        controls.enableZoom = false;
        controls.autoRotate = true;
        controls.autoRotateSpeed = 0.5;

        function loadGLTF(file, inverted) {
            gltfLoader.load(
                file,
                function (gltf) {
                    gltf.scene.traverse((child) => {
                        if (child instanceof THREE.Mesh) {
                            const material = new THREE.MeshStandardMaterial({
                                color: 0x5fa1e3,
                                roughness: 0.8,  // Adjust this value to control shininess (higher values for less shine)
                                metalness: 0.2,  // Adjust this value to control metalness (lower values for less metal-like)
                            });
                            child.material = material;
                        }
                    });
                    gltf.scene.scale.set(inverted ? -5 : 5, 5, 5);
                    scene.add(gltf.scene);
                    if (file == '/neondra-wing.gltf') {
                        if (!inverted) {
                            leftWing = gltf.scene;
                            leftWing.position.z = -2;
                            leftWing.rotation.z = -(targetWingRotation / 78) + 45.1;
                        } else {
                            rightwing = gltf.scene;
                            rightwing.position.z = -2;
                            rightwing.rotation.z = -(targetWingRotation / 78) - 45.1;
                        }
                    }
                },
                function (xhr) {
                    console.log((xhr.loaded / xhr.total * 100) + '% loaded');
                },
                function (error) {
                    console.log('An error happened', error);
                }
            );
        }
        loadGLTF('/neondra1.gltf', false);
        loadGLTF('/neondra-wing.gltf', false);
        loadGLTF('/neondra-wing.gltf', true);

        camera.position.z = 4;
        camera.position.y = -1;

        window.addEventListener('resize', handleResize);
        function handleResize() {
            camera.aspect = window.innerWidth / window.innerHeight;
            camera.updateProjectionMatrix();
            renderer.setSize(window.innerWidth, window.innerHeight);
        }
        handleResize();

        document.getElementById('set-wings').addEventListener('change', function (e) {
            targetWingRotation = document.getElementById('set-wings').value;
        });

        var mouseEnter = false;
        document.getElementsByTagName('canvas')[0].addEventListener('mouseenter', function () {
            mouseEnter = true;
        });
        document.getElementsByTagName('canvas')[0].addEventListener('mouseleave', function () {
            mouseEnter = false;
        });

        var intersects = raycaster.intersectObject(scene, true);

        if (intersects.length > 0) {
            var object = intersects[0].object;
            object.material.color.set(Math.random() * 0xffffff);
        }

        function animate() {
            requestAnimationFrame(animate);
            if (leftWing) {
                leftWing.rotation.z = THREE.MathUtils.lerp(leftWing.rotation.z, -(targetWingRotation / 78) + 45.1, 0.006);
            }
            if (rightwing) {
                rightwing.rotation.z = THREE.MathUtils.lerp(rightwing.rotation.z, -(targetWingRotation / -78) - 45.1, 0.006);
            }
            if (!mouseEnter) controls.update();
            renderer.render(scene, camera);
        }
        animate();
    </script>
    <script>
        // =============>>> VARIABLES <<<============= //
        // I already declared the variables to save some time. I'll just show which elements we selected.
        const coverImg = document.querySelector('.img img');
        const audioName = document.querySelector('.audio-name h1');
        const backwardBtn = document.querySelector('.backwardBtn');
        const forwardBtn = document.querySelector('.forwardBtn');
        const playBtn = document.querySelector('.playBtn');
        const progress = document.querySelector('.progress');
        const progressBar = document.querySelector('.progress-bar');
        const audio = document.querySelector('audio');
        const audioCurrentTime = document.querySelector('.audioCurrentTime');
        const fullLength = document.querySelector('.fullLength');


        const audios = [
            {
                index: 0, // Index must start from 0 (we need it for the music list - NEXT VIDEO)
                name: `4am - KaizanBlu`, // Audios Name
                coverImg: `img/one.jpg`, // Img's path must be correct or the img won't be shown
                audioSrc: `audio/4am - KaizanBlu.mp3` // Audio's path must be correct or the audio won't play
            }, {
                index: 1,
                name: `Chill Jazzy Lofi Hip-Hop Beat Lo-Fi Music`,
                coverImg: `img/two.jpg`,
                audioSrc: `audio/Chill Jazzy Lofi Hip-Hop Beat Lo-Fi Music.mp3`
            }, {
                index: 2,
                name: `Chill Lofi Hip Hop Beat Music`,
                coverImg: `img/three.jpg`,
                audioSrc: `audio/Chill Lofi Hip Hop Beat Music.mp3`
            }, {
                index: 3,
                name: `InRp - Ocean Blue`,
                coverImg: `img/four.jpg`,
                audioSrc: `audio/InRp - Ocean Blue.mp3`
            }
            // You can add as many audios as you want as long as you have these info's
            // example.   Just like that you can add as many as you want.
            // and when there's now enough room we can scroll down but the scroll bar wont show. I think thats a cool trick we learned during this tutorial
        ]

        let current = 0;


        // =============>>> EVENTS <<<============= //
        playBtn.addEventListener('click', playPauseSong);
        forwardBtn.addEventListener('click', playNextSong);
        backwardBtn.addEventListener('click', playPrevSong);
        audio.addEventListener('timeupdate', fillProgress);
        progressBar.addEventListener('click', updateProgress);
        audio.addEventListener('ended', playNextSong)
        // we already created playNextSong function
        // works perfectly
        // today we'll add functionality to the music list. lets continue



        // =============>>> FUNCTIONS <<<============= //

        // PLAY OR PAUSE THE AUDIO
        function playPauseSong() {
            // Check if the audio is playing or paused
            if (audio.duration > 0 && !audio.paused) {
                // Audio is playing
                audio.pause();
                playBtn.innerHTML = `<i class="fas fa-play"></i>`
                coverImg.style.animationPlayState = `paused`
            } else {
                // Audio is paused
                audio.play();
                playBtn.innerHTML = `<i class="fas fa-pause"></i>`
                coverImg.style.animationPlayState = `running`
            }
            // That's all for this function
        }


        // PLAY NEXT AUDIO ON CLICK
        function playNextSong() {
            // Increase current
            current++;
            playSongOnNextOrPrev()
            // we still havent created this function
        }

        // PLAY PREV AUDIO ON CLICK
        function playPrevSong() {
            // Decrease current
            current--;
            playSongOnNextOrPrev()
            // we still havent created this function
        }
        // amateur mistake


        // PLAY THE NEXT OR PREVIOUS SONG DEPENDING ON WHICH BTN WAS CLICKED
        // we'll create that function here.
        function playSongOnNextOrPrev() {
            // Check if the current is higher than the audios length. If yes current = 0. The same if current is lower than 0. This'll help to create a looping audio player.
            if (current > audios.length - 1) {
                current = 0;
            } else if (current < 0) {
                current = audios.length - 1;
            }

            // Change the coverImg, audioName and audioSrc when we get the next or prev song.
            coverImg.src = audios[current].coverImg;
            audioName.innerText = audios[current].name;
            audio.src = audios[current].audioSrc;

            // When we click next or prev we want the audio to play automatically, playBtn to be a pauseBtn and coverImg to be rotating.
            audio.play();
            playBtn.innerHTML = `<i class="fas fa-pause"></i>`
            coverImg.style.animationPlayState = `running`

            // AND THAT'S ALL FOR THIS FUNCTION TOO
        }


        // FILL THE PROGRESS BASED ON AUDIOS FULL LENGTH
        function fillProgress(e) {
            // Get the audio's current time and transform it into percentage. Progress will be filled based on what percentage currently is.
            progress.style.width = `${(e.srcElement.currentTime / e.srcElement.duration) * 100}%`;
            // you can see its getting filled

            // Get mins and secs currentTime and turn them into 00:00 format
            let mins = Math.floor(audio.currentTime / 60);
            let secs = Math.floor(audio.currentTime % 60);
            // Check if currentTime mins or secs are < 10. If yes then add a 0 in front of it.
            if (mins < 10) {
                mins = '0' + mins;
            }
            if (secs < 10) {
                secs = '0' + secs;
            }
            // It Works perfectly now
            audioCurrentTime.innerText = `${mins}:${secs}`;


            // Get the fullLength of the audio and turn them into 00:00 format
            let minutes = parseInt(audio.duration / 60, 10);
            let seconds = parseInt(audio.duration % 60);
            // Check if fullLength mins or secs are < 10. If yes then add a 0 in front of it.
            if (minutes < 10) {
                minutes = '0' + minutes;
            }
            if (seconds < 10) {
                seconds = '0' + seconds;
            }
            fullLength.innerText = `${minutes}:${seconds}`
            // lol. Amateur Mistakes
        }


        // CHANGE THE PROGRESS WIDTH AND AUDIO'S CURRENT TIME BASED ON WHERE WE CLICK ON THE PROGRESS BAR
        function updateProgress(e) {
            audio.currentTime = (e.offsetX / this.clientWidth) * audio.duration;
        }

        // THATS ALL FOR THIS PART. 






        // before starting this tutorial I forgot to add the ended event listener to the audio
        // as you can see when the audio ends nothing happens we want to play the next audio

        // Part #3
        // =============>>> VARIABLES <<<============= //
        // I already declared the variables to save some time. I'll just show which elements we selected.
        const musicList = document.querySelector('.music-list');
        const musicListBtn = document.querySelector('.musicListBtn');
        const xBtn = document.querySelector('.xBtn');
        const list = document.querySelector('.list');




        // =============>>> EVENTS <<<============= //
        musicListBtn.addEventListener('click', showList);
        xBtn.addEventListener('click', removeList);
        window.addEventListener('load', loadAudios);



        // =============>>> FUNCTIONS <<<============= //

        // GIVE THE showMusicList CLASS TO THE MUSIC LIST WHEN WE CLICK THE musicListBtn
        function showList() {
            musicList.classList.add('showMusicList');
        }
        // REMOVE THE showMusicList CLASS FROM THE MUSIC LIST WHEN WE CLICK THE xBtn
        function removeList() {
            musicList.classList.remove('showMusicList');
        }

        // LOAD AUDIOS IN THE MUSIC LIST & ADD A CLICK EVENT FOR EACH SO WE CAN CHANGE THE AUDIO
        function loadAudios() {
            // """map method creates a new array and adds the callback function to each element (or something like that, I'm sorry I can't explain it very well).""" In this case we'll return a html structure for each element in the array.
            let loadedAudios = audios.map(e => {
                return `<div class="item-container" data-index="${e.index}">
                    <div class="item">
                        <div class="coverImg">
                            <img src="${e.coverImg}" alt="">
                        </div>
                        <div class="info">
                            <h3>${e.name}</h3>
                        </div>
                    </div>
                </div>`;
            }).join('');
            list.innerHTML = loadedAudios;
            // this loadedAudios will return an html structure dependig on the audios.length. and for each item-container we changed the index, coverImg and name.  It might be hard to explain. Sorry 🙏🙏🙏

            // Add an event listener for each itemContainer, so when we click it, it'll play the clicked audio. (inside it change the current to the dataset.index, change the coverImg, audiName & audio source)
            const itemContainer = document.querySelectorAll('.item-container');
            itemContainer.forEach(item => {
                item.addEventListener('click', () => {
                    current = item.dataset.index;

                    coverImg.src = audios[current].coverImg;
                    audioName.innerText = audios[current].name;
                    audio.src = audios[current].audioSrc;

                    // now when we click one of the items we want to start playing and now just change the coverImg, audioName audioSrc
                    audio.play();
                    playBtn.innerHTML = `<i class="fas fa-pause"></i>`
                    coverImg.style.animationPlayState = `running`
                })
            })
        }
        // Thats all for this project. Thnx for following until the end
        // and idk if I mentioned
    </script>
</body>
<footer>
    <a onclick="toggleFullScreen();" class="button-fullscreen">
        <img src="./img/fullscreen.png" alt="Go Fullscreen" title="Go Fullscreen">
    </a>
</footer>

</html>
)KEWL";