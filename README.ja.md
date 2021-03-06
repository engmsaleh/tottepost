1タップでポストできるカメラアプリケーション tottepost
=========================================
<img src="http://github.com/kent013/tottepost/raw/master/AppStore/screenshot1.png"
 alt="ScreenShot1" title="ScreenShot1" height = 240 /> 
<img src="http://github.com/kent013/tottepost/raw/master/AppStore/screenshot2_ja.png"
 alt="ScreenShot2" title="ScreenShot2" height = 240 />
<img src="http://github.com/kent013/tottepost/raw/master/AppStore/screenshot3_ja.png"
 alt="ScreenShot3" title="ScreenShot3" height = 240 >
<img src="http://github.com/kent013/tottepost/raw/master/AppStore/screenshot4_ja.png"
 alt="ScreenShot4" title="ScreenShot4" height = 240 />
<img src="http://github.com/kent013/tottepost/raw/master/AppStore/screenshot5_ja.png"
 alt="ScreenShot5" title="ScreenShot5" height = 240 />

[English](https://github.com/kent013/tottepost/blob/master/README.md)

tottepostはシンプルさ、写真や動画を撮ってソーシャルサービスやクラウドサービスにアップロードするために必要な操作の少なさにフォーカスしたiOS用のカメラアプリケーションです。

このアプリケーションは、Instagramのように写真にエフェクトをつけて楽しむカメラアプリケーションではありません。  
そういったアプリケーションは見た目の良いの写真を共有するのには向いています。  
でも、写真をすばやく共有したいと思ったときには、操作が面倒くさいときがありますよね。

tottepostはシンプルさにフォーカスしています。  
エフェクトや写真の切り出し、デコレーションなどはサポートしません。

写真や動画をとってソーシャルサービスやクラウドサービスにアップロードする、それだけのアプリーションです。

[KISS](http://en.wikipedia.org/wiki/KISS_principle).

<a href="http://itunes.apple.com/jp/app/1tappude-xie-zhen-gong-you/id498769617?mt=8&uo=4" target="itunes_store"><img src="http://r.mzstatic.com/images/web/linkmaker/badge_appstore-lrg.gif" alt="1タップで写真共有 - tottepost - ISHITOYA Kentaro" style="border: 0;"/></a>  
[@kent013によるリリース記事](http://d.hatena.ne.jp/kent013/20120211/1328939226)

できること一覧
------------------------------------
 * 写真をソーシャルサービスやクラウドサービスにアップロード
   * Facebook / Twitter / Flickr / Dropbox / Evernote / Picasa / Minus / Mixi / Fotolife
 * 動画をソーシャルサービスやクラウドサービスにアップロード
   * Facebook / Flickr / Dropbox / Minus
 * ローカルのカメラロールに保存
 * コメント入力あり/なしの切り替え
 * ジオタグ埋め込みの切り替え
 * 写真の自動補正
 * 写真／動画の解像度選択<sup>*1</sup>
 * 静音モード<sup>*1*2</sup>
 * バックグラウンドでのアップロード、自動レジューム
 * アルバムの選択
 * アルバムの作成<sup>*1</sup> 

*1 LITEでは使えません。
*2 静音モードではAVCaptureVideoDataOutputを使っているのでmetadataが取得できません。

PhotoSubmitterライブラリ
------------------------------------
PhotoSubmitterライブラリはtottepostのために作られたライブラリです。写真をさまざまなウェブサービスに簡単にアップロードするための抽象化レイヤーを提供します。

詳細は、[https://github.com/kent013/tottepost/tree/master/tottepost/PhotoSubmitter](https://github.com/kent013/tottepost/tree/master/tottepost/PhotoSubmitter) をご覧ください。

ビルドする際の注意点
------------------------------------
シミュレーターはカメラをサポートしていないので、tottepostで写真を取る事はできません。写真のアップロードをテストしたい場合は、シミュレータでカメラボタンをタップしてください。あらかじめ用意された画像がアップロードされます。
また、リポジトリをcloneしたあと、以下のコマンドでsubmoduleをアップデートする必要があります。
```
git submodule init
git submodule update
```
submoduleをアップデートして、`tottepost.xcodeproj`を開くと、UserVoiceAPIKey.hと`PhotoSubmitter/Services/[ServiceName]PhotoSubmitter/[ServiceName]APIKey.h`が存在しないのでビルドエラーになります。

UserVoiceAPIKey.hはUserVoiceSDKを利用するために必要なAPI-KeyとSecretが記述するためのファイルです。UserVoiceAPIKey-template.hをコピーしてtemplateと同じ場所においてください（機能をテストする必要がない場合は、API-KeyとSecretは埋めなくてOKです）

`PhotoSubmitter/Services/[ServiceName]PhotoSubmitter/[ServiceName]APIKey.h`はそれぞれのサービスのAPI-KeyとSecretを記述するためのファイルです。`PhotoSubmitter/Services/[ServiceName]PhotoSubmitter/[ServiceName]APIKey-template.h`をコピーしてtemplateと同じ場所におき、利用したいサービスのAPI-KeyとSecretを取得して記述してください。

もし、すべてのサービスを使いたくない場合には、`PhotoSubmitter/Services/[ServiceName]PhotoSubmitter`をプロジェクトから削除すると機能がOFFになります。

サブモジュールのアップデート
------------------------------------------------
開発者のためのtipsとして書き残しておきますが、PhotoSubmitterを最新バージョンにしてコミットしたい場合は、以下のコマンドを実行してからコミットしてください。
```
git submodule foreach 'git checkout master; git pull'
```


国際化について
------------------------------------
現在、tottepostは英語と日本語に対応しています。またLocalization.stringsを生成するプログラムとして、[twine](https://github.com/mobiata/twine) を使っています。ローカライゼーションを変更したい場合には、先ほどのリンク先のインストラクションに従って、twineをインストールしてください。twineをインストールした後は`./strings.sh`ファイルを実行すれば、stringsファイルが生成されます。


フィードバック
---------------------------------------------------------
issuesに登録するか、[UserVoice](http://tottepost.uservoice.com/)までご連絡ください。

作者
------------------------------------
 * 石戸谷 顕太朗 [@kent013](http://twitter.com/kent013) メール:kentaro.ishitoya at gmail.com
 * 渡辺 賢 [@ken4500](http://twitter.com/ken4500)

配布について
------------------------------------
このアプリケーションをそのままAppleのAppStoreで配布することは、特段の理由がないと許容致しかねます。
"そのまま"でない場合はライセンスに従ってください。

ライセンス
------------------------------------
Copyright (c) 2011, ISHITOYA Kentaro.  
Copyright (c) 2011, WATANABE Ken.  

修正BSDライセンスです。 [LICENSE](https://github.com/kent013/tottepost/blob/master/LICENSE)をご覧ください。

変更履歴
------------------------------------
AppStoreの最新バージョンは1.1です。
[CHANGELOG](https://github.com/kent013/tottepost/blob/master/CHANGELOG.md)をご覧ください。

サードパーティライブラリ
------------------------------------
[サードパーティライブラリの一覧](https://github.com/kent013/tottepost/blob/master/3RDPARTY.md)をご覧ください。